import itertools
def solution(N):
	ls = list(str(N))
	init_len = len(ls)
	all_perms = list(itertools.permutations(ls))
	ans = set()
	for x in all_perms:
		s = ''.join(x)
		num = int(s)
		s = str(num)
		if len(s) == init_len:
			ans.add(s)
	return len(ans)


print solution(780)

print solution(100)

print solution(4321)

print solution(1213)

print solution(99999)

print solution(12345)

print solution(100000)
