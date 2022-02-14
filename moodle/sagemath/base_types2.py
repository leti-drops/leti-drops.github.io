def print_list(lst):
	print(' '.join(map(str, lst)))

def reverse_neighbours(lst):
	for i in range(int(len(inp) / 2)):
		lst[i*2], lst[i*2+1] = lst[i*2+1], lst[i*2]

inp = list(map(int, input().split()))

inp_even = []
for i in range(len(inp)):
	if i % 2 == 0:
		inp_even.append(inp[i])
print_list(inp_even)

print(max(inp), inp.index(max(inp)))
inp.reverse()
print_list(inp)
inp.reverse()

reverse_neighbours(inp)
print_list(inp)
reverse_neighbours(inp)

inp.sort(key = lambda x : x % 7)
print_list(inp)
