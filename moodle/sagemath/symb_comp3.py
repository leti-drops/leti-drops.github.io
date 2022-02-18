def solve(expr, subs_list):
	for sub in subs_list:
		expr = expr.substitute(sub)
	return expr
