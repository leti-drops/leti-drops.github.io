from sage.calculus.functional import diff
from sage.symbolic.relation import solve
from sage.matrix.constructor import matrix
from sage.rings.real_mpfr import RealField

def solution(lst1, lst2):
	return true

def f(func, list_):
	eqsys = []
	for v in list_:
		eqsys.append(diff(func, v) == 0)
	eqsol = solve(eqsys, list_)
	res = []

	for sol in eqsol:
		static_pt = [0] * len(list_)
		for eq in sol:
			for v in list_:
				if v == eq.default_variable():
					static_pt[list_.index(v)] = eq.right()
					break
		#print(static_pt)

		gesse_mat = matrix(RealField(), len(list_), len(list_))
		for i in range(0, len(list_)):
			for j in range(0, len(list_)):
				d = diff(diff(func, list_[i]), list_[j])
				for v in list_:
					d = d.substitute(v == static_pt[list_.index(v)])
				gesse_mat[i, j] = d

		#print(gesse_mat)
		if gesse_mat[0, 0] < 0:
			gesse_type = 'negative'
			gesse_prev_sign = -1
		else:
			gesse_type = 'positive'
		for n in range(2, len(list_)):
			if gesse_type == 'positive' and gesse_mat[0:n, 0:n].det() < 0:
				gesse_type = 'undefined'
				break
			elif gesse_type == 'negative':
				gesse_cur_sign = -1 if gesse_mat[0:n, 0:n].det() < 0 else 1
				if gesse_cur_sign == gesse_prev_sign:
					gesse_type = 'undefined'
					break
				gesse_prev_sign = gesse_cur_sign

		#print(gesse_type)
		if gesse_type == 'negative' or gesse_type == 'positive':
			res.append(tuple(static_pt))

	return res
