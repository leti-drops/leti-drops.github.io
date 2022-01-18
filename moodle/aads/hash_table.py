class hash_table:

# pair: (key, value)

    def __init__(self, size):
        self.pairs = [(None, None)] * size


    def insert(self, pair):
        h = pair[0] % len(self.pairs)
        while h < len(self.pairs) and self.pairs[h][0] != None and self.pairs[h][0] != pair[0]:
            h += 1

        if h < len(self.pairs):
            self.pairs[h] = pair


    def delete(self, key):
        h = key % len(self.pairs)
        while h < len(self.pairs):
            if self.pairs[h][0] == key:
                self.pairs[h] = (None, None)
            h += 1


    def find(self, key):
        h = key % len(self.pairs)
        while h < len(self.pairs) and self.pairs[h][0] != key:
            h += 1

        if h >= len(self.pairs):
            return None
        return self.pairs[h][1]



n = int(input())
ht = hash_table(n)

for i in range(0, n):
    a = input().split()

    if a[0] == "add":
        ht.insert((int(a[1]), ' '.join(a[2:len(a)])))
    elif a[0] == "del":
        ht.delete(int(a[1]))
    elif a[0] == "find":
        val = ht.find(int(a[1]))
        if val == None:
            print("not found")
        else:
            print(val)
