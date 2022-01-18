class node:
    def __init__(self, key, left, right):
        self.key = key
        self.left = left
        self.right = right


class tree:
    def __init__(self, in_arr):
        self.nodes = [None] * len(in_arr)

        for i in range(0, len(in_arr)):
            self.nodes[i] = node(in_arr[i][0], in_arr[i][1], in_arr[i][2])


    def trav_inorder(self):
        self.print_beg = '' # спасибо МОЭВМ
        self._trav_inorder(0)
        print('')
    def _trav_inorder(self, root_i): # левое поддерево, корень, правое поддерево
        if root_i == -1:
            return
        self._trav_inorder(self.nodes[root_i].left)
        print(self.print_beg, self.nodes[root_i].key, sep = '', end = '')
        self.print_beg = ' '
        self._trav_inorder(self.nodes[root_i].right)


    def trav_preorder(self):
        self.print_beg = ''
        self._trav_preorder(0)
        print('')
    def _trav_preorder(self, root_i): # корень, левое поддерево, правое поддерево
        if root_i == -1:
            return
        print(self.print_beg, self.nodes[root_i].key, sep = '', end = '')
        self.print_beg = ' '
        self._trav_preorder(self.nodes[root_i].left)
        self._trav_preorder(self.nodes[root_i].right)


    def trav_postorder(self):
        self.print_beg = ''
        self._trav_postorder(0)
        print('')
    def _trav_postorder(self, root_i): # левое поддерево, правое поддерево, корень
        if root_i == -1:
            return
        self._trav_postorder(self.nodes[root_i].left)
        self._trav_postorder(self.nodes[root_i].right)
        print(self.print_beg, self.nodes[root_i].key, sep = '', end = '')
        self.print_beg = ' '


n = int(input())
inp = []
for i in range(0, n):
    inp.append(tuple(map(int, input().split())))

t = tree(inp)
t.trav_inorder()
t.trav_preorder()
t.trav_postorder()
