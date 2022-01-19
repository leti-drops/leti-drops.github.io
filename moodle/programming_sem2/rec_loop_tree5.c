#include <stdio.h>

int recSum(int *arr, int ind)
{
        if(ind == 0)
                return arr[0];
        return arr[0] + recSum(arr+1, ind-1);
}

int main()
{
        int arr[100];
        for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i)
        {
                scanf("%d", arr+i);
        }

        printf("%d\n", recSum(arr, 99));
        return 0;
}
