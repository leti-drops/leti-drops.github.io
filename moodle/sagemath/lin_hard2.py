from sage.rings.integer_ring import IntegerRing
from sage.matrix.constructor import matrix

def f(n):
	mat = matrix(IntegerRing(), n, n)
	for i in range(0, n):
		for j in range(0, n):
			mat[i, j] = (i + 1) * (j + 1)
	return mat
