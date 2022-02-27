F.<a, b> = FreeGroup()
G = F/[a^4, b^4, (a*b)^2, (a^(-1)*b)^2]


def allElem(G):
    return [G.list(), G.order()]


def reverseElems(G):
    res = []
    for el in G.list():
        res.append(el.inverse())
    return res


def center(G):
    return G.center()
