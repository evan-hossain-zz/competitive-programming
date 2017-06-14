test = int(input())
while test>0:
	test -= 1
	u, v = map(int, input().split())
	n = u + v
	cur = 1
	rank = n*(n+1)//2 + 1
	rank += u
	print(rank)