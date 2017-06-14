test = int(input())
for t in range(test):
	arr = list()
	n, k = map(int, input().split())
	res = 0
	for i in range(n):
		cur_list = [int(x)-1 for x in input().split()[1:]]
		arr.append(cur_list)
	for cur_list in arr:
	print(res//2)

'''
1
3 4
3 1 2 3
4 1 2 3 4
3 2 3 4
'''