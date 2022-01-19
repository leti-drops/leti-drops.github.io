#include <stdio.h>

long count(long N)
{
	long c = 0;
	while(N > 0){
		c += N & 1;
		N >>= 1;
	}
	return c;
}

int main()
{
        // Unit-test
	assertEqual(count(502318025844858307), 30);
	assertEqual(count(101), 4);
	assertEqual(count(68319), 10);
	assertEqual(count(959112), 8);
	assertEqual(count(196921), 7);

        // Main code
        long n;
        scanf("%ld", &n);
        printf("%ld\n", count(n));
        return 0;
}
