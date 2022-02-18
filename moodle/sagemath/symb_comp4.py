from math import sqrt

def is_prime(num):
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

def solve(dividend, divisor):
    res = []
    res.append(dividend.coefficients(sparse=False)[::-1])
    res.append(divisor.coefficients(sparse=False)[::-1])
    quot,rem = dividend.quo_rem(divisor)
    res.append(rem)

    primes = []
    for i in range(-100, 100):
        n = int(rem(x=i))
        if n >= 0 and (is_prime(n) or int(math.sqrt(n))**2 == n):
            primes.append(i)
    res.append(primes)
    res.append(dividend.gcd(divisor))
    res.append(dividend * divisor)
    return res
