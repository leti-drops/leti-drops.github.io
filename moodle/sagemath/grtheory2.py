def solve(f_coeff, n):
	F.<a> = FiniteField(n)
	finpoly.<x> = PolynomialRing(F)

	f = 0
	n = 0
	for coff in f_coeff:
		if coff == 0 and n == 0:
			n += 1
			continue
		f += coff * (x ** n)
		n += 1

	return str(factor(f))
