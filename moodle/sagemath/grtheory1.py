def solve(f_coeff, g_coeff, n):
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
	n = 0
	g = 0
	for coff in g_coeff:
		if coff == 0 and n == 0:
			n += 1
			continue
		g += coff * (x ** n)
		n += 1

	[d, r, s] = xgcd(g, f)
	print(f, g)

	return str(d) + " = (" + str(s) + ") * (" + str(f) + ") + (" + str(r) + ") * (" + str(g) + ")"
