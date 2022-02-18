from sage.symbolic.operators import mul_vararg

mul_cnt = 0
def solve(expr):
	global mul_cnt
	mul_cnt = 0
	def solve_rec(expr):
		global mul_cnt
		if expr.operator() is mul_vararg:
			mul_cnt += len(expr.operands()) - 1
		for operand in expr.operands():
			solve_rec(operand)
	solve_rec(expr)
	return mul_cnt
