def double_comp(a, b):
        diff = a - b
        if abs(diff) < 0.00001:
            return 0
        elif diff < 0:
            return -1
        return 1

def solve(L, x):
        left = 0
        right = len(L) - 1

        while left <= right:
                m = int((right + left) / 2)
                if double_comp(L[m], x) == 0:
                        return m
                elif double_comp(L[m], x) > 0:
                        right = m - 1
                elif double_comp(L[m], x) < 0:
                        left = m + 1
        return -1
