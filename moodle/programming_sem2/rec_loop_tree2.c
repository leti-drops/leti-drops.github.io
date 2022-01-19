#include <stdio.h>

double recPow(int num, int pow)
{
        if(pow == 0)
                return 1;
        if(num == 0)
                return 0;

        if(pow > 0){
                if(pow % 2 == 0){
                        int halfnum = recPow(num, pow/2);
                        return halfnum * halfnum;
                }
                else{
                        return num * recPow(num, pow-1);
                }
        }
        else{
                return 1.0 / recPow(num, -pow);
        }
}

int main()
{
        int n, p;
        double res;
        scanf("%d%d", &n, &p);
        res = recPow(n, p);
        printf("%g", res);
        return 0;
}
