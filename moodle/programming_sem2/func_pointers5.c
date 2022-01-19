#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Country{
	char name[30];
	unsigned int population;
	char capital[30];
};


int country_cmp(const void* a1, const void* a2)
{
	struct Country* c1 = (struct Country*)a1;
	struct Country* c2 = (struct Country*)a2;

	int _cmp = strcmp(c1->name, c2->name);
	if(_cmp) return _cmp;
	if(c1->population < c2->population) return -1;
	return c1->population > c2->population;
}

int main()
{
	struct Country* ctr_arr;
	size_t ctr_arr_sz;
	scanf("%lu", &ctr_arr_sz);
	ctr_arr = malloc(sizeof(struct Country) * ctr_arr_sz);
	if(!ctr_arr){
		fprintf(stderr, "Couldn't allocate memory.\n");
		return 1;
	}

	for(size_t i = 0; i < ctr_arr_sz; ++i)
	{
		struct Country* c = &ctr_arr[i];
		scanf("%30s %u %30s\n", c->name, &c->population, c->capital);
	}

	qsort(ctr_arr, ctr_arr_sz, sizeof(struct Country), &country_cmp);

	for(size_t i = 0; i < ctr_arr_sz; ++i){
		struct Country* c = &ctr_arr[i];
		printf("%s %u %s", c->name, c->population, c->capital);
		if(i != ctr_arr_sz - 1)
			printf(" ");
	}
}
