def solve():
	zzpoly.<x> = PolynomialRing(ZZ)
	fin = GF(25, 'a', modulus = zzpoly([3, 2, 1]))
	return [(fin.gen()^7 + 1).log(fin.gen()), (fin.gen()^17 + 1).log(fin.gen())]
