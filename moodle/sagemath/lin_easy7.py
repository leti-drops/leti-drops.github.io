from sage.matrix.constructor import matrix
from sage.rings.real_mpfr import RealField

def f(ma):
	res = matrix(RealField(), len(ma.rows()), 2)
	i = 0
	for r in ma.rows():
		a = r[0]
		b = r[1]
		c = r[2]
		res[i, 0] = -a/b
		res[i, 1] = -c/b
		i += 1
	return res
