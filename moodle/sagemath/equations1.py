from sage.calculus.functional import diff
from sage.calculus.var import var
from sage.misc.functional import integral

def solve(df, idf, iif, dif, a, b):
	var('x y')
	_diff = diff(df, x, 1)
	_idiff = diff(idf, x, 1) / diff(idf, y, 1)
	_int = integral(iif, x)
	_dint = integral(dif, x, a, b)

	return [_diff, _idiff, _int, _dint]
