def f(a, x):
	res = 0
	x_mul = 1
	for el in a:
		res += el * x_mul
		x_mul *= x
	return res
