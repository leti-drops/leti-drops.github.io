#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_BUF_SZ 1001

char** input(char* buf, size_t* sent_arr_sz_out)
{
	char** sent_arr = NULL;
	size_t sent_arr_sz = 0;

	char* buf_it;
	for(buf_it = buf;; ++buf_it)
	{
		*buf_it = getchar();

		if(*buf_it == '.'){
			++sent_arr_sz;
			char** tmp = (char**)realloc(sent_arr, sent_arr_sz * sizeof(char*));
			if(!tmp){
				if(sent_arr) free(sent_arr);
				return NULL;
			}
			sent_arr = tmp;

			buf_it[1] = '\0';
			sent_arr[sent_arr_sz-1] = strdup(buf[0] == ' ' ? buf+1 : buf);

			buf_it = buf-1;
		}
		else if(*buf_it == '\n')
			break;
	}

	*sent_arr_sz_out = sent_arr_sz;
	return sent_arr;
}

int sent_cmp(const void* a1, const void* a2)
{
	char* s1 = *((char**)a1);
	char* s2 = *((char**)a2);
	size_t ln1 = strlen(s1); size_t ln2 = strlen(s2);

	if(ln1 < ln2) return -1;
	return ln1 > ln2;
}

int main()
{
	char str_buf[STR_BUF_SZ];
	char** sent_arr;
	size_t sent_arr_sz;

	sent_arr = input(str_buf, &sent_arr_sz);
	if(!sent_arr){
		fprintf(stderr, "Couldn't allocate memory.\n");
		return 1;
	}

	qsort(sent_arr, sent_arr_sz, sizeof(char*), &sent_cmp);
	for(size_t i = 0; i < sent_arr_sz; ++i){
		if(i != 0)
			printf(" ");
		printf("%s", sent_arr[i]);
	}
}
