from sage.symbolic.operators import add_vararg, mul_vararg
from sage.symbolic.operators import arithmetic_operators

def op_argnum(op, _default):
	try:
		return op.number_of_arguments()
	except:
		return 2

def solve(expr):
	global out_str
	out_str = ""
	def solve_rec(expr):
		global out_str
		operands_printed = 0
		for operand in expr.operands():
			if operand.operator() is None:
				out_str += str(operand) + ' '
			else:
				solve_rec(operand)
			operands_printed += 1
			if operands_printed >= op_argnum(expr.operator(), len(expr.operands())):
				out_str += arithmetic_operators[expr.operator()] + ' '
		if len(expr.operands()) == 0 and expr.operator() is None:
			out_str += str(expr)

	solve_rec(expr)
	return out_str.strip()
