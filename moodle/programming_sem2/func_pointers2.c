#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DOUBLE_CMP_PRECISION 0.0001

int universalMax(void* array, size_t nmemb, size_t elsz, int (*cmp)(const void*, const void*))
{
	void* max = array;

	void* array_end = array + nmemb * elsz;
	for(void* it = array + elsz; it < array_end; it += elsz)
	{
		if(cmp(it, max) > 0)
			max = it;
	}

	return (max - array) / elsz;
}

int cmp_char(const void* a1, const void* a2)
{
	const char c1 = *((const char*)a1); const char c2 = *((const char*)a2);
	if(c1 < c2) return -1;
	return c1 > c2;
}
int cmp_int(const void* a1, const void* a2)
{
	const int c1 = *((const int*)a1); int c2 = *((const int*)a2);
	if(c1 < c2) return -1;
	return c1 > c2;
}
int cmp_double(const void* a1, const void* a2)
{
	double c1 = *((const double*)a1); double c2 = *((const double*)a2);
	c1 = round(c1 / DOUBLE_CMP_PRECISION) * DOUBLE_CMP_PRECISION;
	c2 = round(c2 / DOUBLE_CMP_PRECISION) * DOUBLE_CMP_PRECISION;
	if(c1 < c2) return -1;
	return c1 > c2;
}


int main()
{
	int choice;
	scanf("%d", &choice);
	int maxi = -1;

	switch(choice)
	{
		case 1:
		{
			char arr[20];
			for(size_t i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i)
				scanf(" %c", arr + i);
			maxi = universalMax(arr, sizeof(arr)/sizeof(arr[0]), sizeof(arr[0]), &cmp_char);
			break;
		}
		case 4:
		{
			int arr[20];
			for(size_t i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i)
				scanf("%d", arr + i);
			maxi = universalMax(arr, sizeof(arr)/sizeof(arr[0]), sizeof(arr[0]), &cmp_int);
			break;
		}
		case 8:
		{
			double arr[20];
			for(size_t i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i)
				scanf("%lf", arr + i);
			maxi = universalMax(arr, sizeof(arr)/sizeof(arr[0]), sizeof(arr[0]), &cmp_double);
			break;
		}
		default:
			printf("Error\n");
			return 0;
	}

	printf("%d\n", maxi);
	return 0;
}
