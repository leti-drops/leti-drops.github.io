from sage.calculus.var import var
from sage.symbolic.expression import solve_diophantine

def gcdex(a, b):
	def egcd(a, b):
		if b == 0:
			return [a, 1, 0]
		_gcd, x1, y1 = egcd(b, a % b)
		x = y1 - (b / a) * x1
		y = x1
		return [_gcd, x, y]

	[d, _, _] = egcd(a, b)
	x, y = var('x y')
	eq = (a*x + b*y == d)
	dioph_sol = solve_diophantine(eq)
	return [d, dioph_sol[0](t_0 = 0), dioph_sol[1](t_0 = 0)]
