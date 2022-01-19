#include <stdio.h>

long sum(long a, long b){ return a + b; }

int main()
{
        // Unit-test
        assertEqual(sum(8, 2), 10);
        assertEqual(sum(4, 17), 21);
        assertEqual(sum(-5, 21), 16);
        assertEqual(sum(-17, 9), -8);
        assertEqual(sum(-6, -17), -23);

        // Main code
        long n, m;
        scanf("%ld%ld", &n, &m);
        printf("%ld\n", sum(n, m));
        return 0;
}
