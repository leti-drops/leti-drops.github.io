#include <stdio.h>
#include <stdlib.h>

int haspath(int x, int y,
            int n, int m, unsigned char* field)
{
        if(x == m-1 && y == n-1)
                return 1;

        field[y*m + x] = 1;

        // left
        if(x > 0 && field[y*m + (x - 1)] == 0)
                if(haspath(x - 1, y, n, m, field))
                        return 1;
        // right
        if(x < m-1 && field[y*m + (x + 1)] == 0)
                if(haspath(x + 1, y, n, m, field))
                        return 1;
        // up
        if(y > 0 && field[(y - 1)*m + x] == 0)
                if(haspath(x, y - 1, n, m, field))
                        return 1;
        // down
        if(y < n-1 && field[(y + 1)*m + x] == 0)
                if(haspath(x, y + 1, n, m, field))
                        return 1;

        return 0;
}

int main()
{
        int n, m;
        scanf("%d%d", &n, &m);
        unsigned char* field = malloc(n*m);
        for(int i = 0; i < n*m; ++i)
                scanf("%hhu", field + i);

        if(haspath(0, 0,
                   n, m, field))
                printf("exists\n");
        else
                printf("doesn't exist\n");
}
