#include <stdio.h>
#include <string.h>

long count(const char* s)
{
	const char* word_beg, *word_end;
	const char* word_beg2, *word_end2;
	int flag1 = 0, flag2 = 0;
	long max_cnt = 0, cur_cnt = 0;
	for(; *s; ++s)
	{
		if(flag1 == 0 && *s != ' '){
			word_beg = s;
			flag1 = 1;
		}
		else if(flag1 == 1 && *s == ' '){
			flag1 = 0;

			word_end = s-1;
			const char* it = s;
			flag2 = 0; cur_cnt = 0;
			for(; it[-1]; ++it)
			{
				if(flag2 == 0 && *it != ' '){
					word_beg2 = it;
					flag2 = 1;
				}
				else if(flag2 == 1 && (*it == ' ' || *it == '\0')){
					flag2 = 0;

					word_end2 = it-1;
					size_t wlen1 = word_end - word_beg + 1;
					size_t wlen2 = word_end2 - word_beg2 + 1;
					if(wlen1 == wlen2 && !strncmp(word_beg, word_beg2, wlen1)){
						++cur_cnt;
					}
				}
			}
			if(cur_cnt > max_cnt) max_cnt = cur_cnt;
		}
	}
	return max_cnt + 1;
}

int main()
{
        // Unit-test
	assertEqual(count("mw  wue minpvrxnos aivedg mqfpv  pbhlzfpi zj l ri yopzw tnxy  sy u rgrklr y  hkxs mpbjyk mswm y dheydp m  r zeicyqgyif"), 2);

        // Main code
	char s[201];
	fgets(s, sizeof(s), stdin);
	if(s[strlen(s)-1] == '\n')
		s[strlen(s)-1] = '\0';
        printf("%ld\n", count(s));
        return 0;
}
