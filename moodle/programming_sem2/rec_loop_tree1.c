#include <stdio.h>

long long int recFact(long long int a)
{
    if(a <= 1)
        return 1;
    return a * recFact(a-1);
}

int main()
{
    long long int num;
    scanf("%lld", &num);
    printf("%lld", recFact(num));
}
