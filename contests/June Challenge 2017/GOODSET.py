test = int(input())
while test>0:
	test -= 1
	n = int(input())
	num = 1
	for i in range(n):
		print(num, end=' ')
		num += 2
	print('')