from sage.misc.functional import integral
from sage.calculus.var import var
from sage.functions.other import sqrt
from sage.symbolic.assumptions import assume

def solve():
	var('x y p')
	assume(p > 0)
	return integral(integral(x*y**2, y, -sqrt(2*p*x), sqrt(2*p*x)), x, 0, p/2)
