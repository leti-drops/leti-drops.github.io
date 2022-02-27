F.<a, b> = FreeGroup()
G = F/[a^4, b^4, (a*b)^2, (a^(-1)*b)^2]

def conjugateElemsClass(G):
	present = []
	res = []
	first = true
	for base in G.list():
		cls = []
		for gn in G.list():
			elem = gn * base * gn ^ (-1)
			if elem not in present:
				present.append(elem)
				cls.append(elem)
		if len(cls) != 0:
			res.append(cls)
	return res
