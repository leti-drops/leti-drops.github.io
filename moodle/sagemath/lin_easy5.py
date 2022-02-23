def f(A):
	N = len(A.rows())
	return A[int(N/2):N, int(N/2):N]
