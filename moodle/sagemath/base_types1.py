def solve(list_arg):
	answer = []
	for i in range(len(list_arg)):
		for j in range(i+1, len(list_arg)):
			answer.append(str(Sequence([list_arg[i], list_arg[j]]).universe()))
	return answer
