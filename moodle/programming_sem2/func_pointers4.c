#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
	char name[30];
	char author[30];
	unsigned int pages;
	char isbn[20];
};


int book_cmp(const void* a1, const void* a2)
{
	struct Book* b1 = (struct Book*)a1;
	struct Book* b2 = (struct Book*)a2;

	return -strcmp(b1->author, b2->author);
}

int main()
{
	struct Book* book_arr;
	size_t book_arr_sz;
	scanf("%lu", &book_arr_sz);
	book_arr = malloc(sizeof(struct Book) * book_arr_sz);
	if(!book_arr){
		fprintf(stderr, "Couldn't allocate memory.\n");
		return 1;
	}

	for(size_t i = 0; i < book_arr_sz; ++i)
	{
		struct Book* b = &book_arr[i];
		scanf("%30s %20s %u %20s\n", b->name, b->author, &b->pages, b->isbn);
	}

	qsort(book_arr, book_arr_sz, sizeof(struct Book), &book_cmp);
	for(size_t i = 0; i < book_arr_sz; ++i){
		printf("%s %s %u %s", book_arr[i].name, book_arr[i].author, book_arr[i].pages, book_arr[i].isbn);
		if(i != book_arr_sz-1)
			printf(" ");
	}
}
