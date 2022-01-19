#include <stdlib.h>
#include <stdio.h>

void forEachElement(int* array, size_t n, int (*func)(int))
{
        for(size_t i = 0; i < n; ++i)
        {
                array[i] = func(array[i]);
        }
}

int func_mul2(int a) { return a << 1; }
int func_pow3(int a) { return a*a*a; }
int func_abs(int a) { return a >= 0 ? a : -a; }

int main()
{
        int arr[500];
        for(size_t i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i)
                scanf("%d", arr + i);
        int choice;
        scanf("%d", &choice);

        int (*choice_func)(int);
        switch(choice)
        {
                case 1: choice_func = func_mul2; break;
                case 2: choice_func = func_pow3; break;
                case 3: choice_func = func_abs; break;
                default:
                        printf("Error");
                        return 0;
        }

        forEachElement(arr, sizeof(arr)/sizeof(arr[0]), choice_func);

        for(size_t i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i)
                if(i == sizeof(arr)/sizeof(arr[0])-1)
                    printf("%d", arr[i]);
                else
                    printf("%d\n", arr[i]);
}
