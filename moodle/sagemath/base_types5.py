def cmp_to_key(mycmp):
	class K(object):
		def __init__(self, obj, *args):
			self.obj = obj
		def __lt__(self, other):
			return mycmp(self.obj, other.obj) < 0
		def __gt__(self, other):
			return mycmp(self.obj, other.obj) > 0
		def __eq__(self, other):
			return mycmp(self.obj, other.obj) == 0
		def __le__(self, other):
			return mycmp(self.obj, other.obj) <= 0
		def __ge__(self, other):
			return mycmp(self.obj, other.obj) >= 0
		def __ne__(self, other):
			return mycmp(self.obj, other.obj) != 0
	return K

def candidate_cmp(cnd1, cnd2):
	if cnd1[1] < cnd2[1]:
		return 1
	elif cnd1[1] > cnd2[1]:
		return -1
	elif cnd1[0] < cnd2[0]:
		return -1
	elif cnd1[0] > cnd2[0]:
		return 1
	else:
		return 0

state_cnt = int(input())
states = {}
for i in range(state_cnt):
	inp = input().split()
	states[inp[0]] = int(inp[1])


vote_cnt = int(input())
votes = {}
for i in range(vote_cnt):
	inp = input().split()
	if inp[0] not in votes:
		votes[inp[0]] = {}
	if inp[1] not in votes[inp[0]]:
		votes[inp[0]][inp[1]] = 0
	votes[inp[0]][inp[1]] += 1

votes2 = {}
for i in range(len(votes)):
	state_votes = list(votes.values())[i]

	for j in range(0, len(state_votes.values())):
		if list(state_votes.keys())[j] not in votes2:
			votes2[list(state_votes.keys())[j]] = 0

	_max = list(state_votes.items())[0]
	for j in range(1, len(state_votes.items())):
		if list(state_votes.items())[j][1] > _max[1]:
			_max = list(state_votes.items())[j]
		elif list(state_votes.items())[j][1] == _max[1] and list(state_votes.items())[j][0] < _max[0]:
			_max = list(state_votes.items())[j]

	votes2[_max[0]] += states[list(votes.keys())[i]]

_out = list(votes2.items())
_out.sort(key = cmp_to_key(candidate_cmp))
for cnd in _out:
	print(' '.join([cnd[0], str(cnd[1])]))
