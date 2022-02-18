from sage.symbolic.relation import solve
from sage.calculus.var import var
from sage.calculus.calculus import limit
from sage.rings.infinity import *

def find_vasymptotes(f):
	return solve(f.denominator() == 0, x)

def find_hasymptotes(f):
	res = []
	k1 = limit(f / x, x = infinity)
	if not k1.is_infinity():
		b1 = limit(f - k1*x, x = infinity)
		if not b1.is_infinity():
			res.append(k1*x + b1)

	k2 = limit(f / x, x = -infinity)
	if not k2.is_infinity():
		b2 = limit(f - k2*x, x = -infinity)
		if not b2.is_infinity() and (k1 != k2 or b1 != b2):
			res.append(k2*x + b2)

	return res

def asymptotes(f):
	var('x')
	res = []
	for a in find_vasymptotes(f):
		res.append(str(a.left()) + " = " + str(a.right()))
	for a in find_hasymptotes(f):
		res.append("y = " + str(a))
	return res
