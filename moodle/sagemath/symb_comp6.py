from sage.rings.power_series_ring import PowerSeriesRing
from sage.interfaces.r import R
from sage.calculus.var import var

def solve(h):
	res = []

	var('x')
	s = h.series(x, 10)
	res.append(s)
	s = s.truncate()
	res.append(s.leading_coefficient(x))

	t = h.taylor(x, 4, 9)
	res.append(t)
	res.append(t.full_simplify().leading_coefficient(x))

	res = list(map(str, res))
	return res
