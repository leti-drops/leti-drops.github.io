def f(A, B):
	return A * B.T * A.norm(1) * B.norm(2)
