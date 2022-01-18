class stack_node:

    def __init__(self, c, i, prev = None):
        self.c = c
        self.i = i
        self.prev = prev

class stack:

    def __init__(self):
        self.last_node = stack_node(0, 0)
        self.last_node.prev = self.last_node

    def push(self, c, i):
        new_node = stack_node(c, i, self.last_node)
        self.last_node = new_node

    def pop(self):
        out_c = self.last_node.c
        out_i = self.last_node.i
        self.last_node = self.last_node.prev
        return (out_c, out_i)

    def empty(self):
        return self.last_node.prev == self.last_node


def is_brace_open(c):
    return c == '(' or c == '[' or c == '{'
def is_brace_close(c):
    return c == ')' or c == ']' or c == '}'
def brace_matches(open, close):
    if     open == '(': return close == ')'
    elif    open == '[': return close == ']'
    elif    open == '{': return close == '}'


s = stack()
a = input()
i = 0
for c in a:
    if is_brace_open(c):
        s.push(c, i)
    elif is_brace_close(c):
        if s.empty():
            print(i + 1)
            exit()
        [br_c, br_i] = s.pop()
        if not brace_matches(br_c, c):
            print(i + 1)
            exit()

    i += 1

if not s.empty():
    while not s.empty():
        [br_c, br_i] = s.pop()
    print(br_i + 1)
else:
    print("Success")
