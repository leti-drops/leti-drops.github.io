#include <stdio.h>

double pow_(long num, long pow)
{
    long onum = num, opow = pow > 0 ? pow : -pow;
    num = 1;
    for(long p = 0; p < opow; ++p)
        num *= onum;
    return pow >= 0 ? (double)num : 1.0 / num;
}

int main()
{
        // Unit-test
	assertEqual(pow_(0, 10), 0);
	assertEqual(pow_(1, 0), 1);
	assertEqual(pow_(1, 1), 1);
	assertEqual(pow_(2, 2), 4);
	assertEqual(pow_(3, 0), 1);

        // Main code
        long n, m;
        scanf("%ld %ld", &n, &m);
        printf("%lf\n", pow_(n, m));
        return 0;
}
