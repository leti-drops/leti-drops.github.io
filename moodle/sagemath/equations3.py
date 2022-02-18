from sage.calculus.var import var

def solve(f):
	var('x z')
	if f == z:
		f = x

	_diff = f
	ops = _diff.operands()
	if len(ops) == 0:
		ops = [_diff]
	for op in ops:
		if op.default_variable() != x:
			continue
		tosub = op.leading_coeff(x) * x ** op.degree(x)
		toadd = op.leading_coeff(x) * (op.degree(x)) * x ** (op.degree(x) - 1)
		_diff = _diff - tosub + toadd

	_int = f
	ops = _int.operands()
	if len(ops) == 0:
		ops = [_int]
	for op in ops:
		if op.default_variable() != x:
			continue
		tosub = op.leading_coeff(x) * x ** op.degree(x)
		toadd = op.leading_coeff(x) / (op.degree(x) + 1) * x ** (op.degree(x) + 1)
		_int = _int - tosub + toadd

	return [_diff, _int]
