from sage.matrix.constructor import matrix
from sage.functions.trig import *

def f(alpha, x):
	if len(x) == 2:
		return (matrix([[cos(alpha), -sin(alpha)], [sin(alpha), cos(alpha)]]) * x).n()
	elif len(x) == 3:
		return (matrix([[cos(alpha), 0, sin(alpha)], [0, 1, 0], [-sin(alpha), 0, cos(alpha)]]) * x).n()
