def solve(f, g):
	res = []

	ineq = f**2 >= g**2
	res_2 = []
	for i in range(-10, 11):
		if bool(ineq(x=i)):
			res_2.append(i)
	res.append(res_2)

	g = g**2
	m = g.find_local_minimum(-10, 10)
	res.append("{:.18f}".format(m[0]))
	res.append("{:.18f}".format(m[1]))
	f = f**2
	M = f.find_local_maximum(-10, 10)
	res.append("{:.18f}".format(M[0]))
	res.append("{:.18f}".format(M[1]))

	return res
