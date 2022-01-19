#include <stdio.h>

void recIn(int ind, int dospace)
{
        int num;
        scanf("%d", &num);

        if(ind > 0)
                recIn(ind-1, 1);

        if(dospace)
                printf("%d ", num);
        else
                printf("%d", num);
}

int main()
{
        int N;
        scanf("%d", &N);
        if(N > 0)
        recIn(N-1, 0);
}
