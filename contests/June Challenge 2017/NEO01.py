test = int(input())
for t in range(test):
	n = int(input())
	count = 0
	res = 0
	exclude = 0
	for number in sorted(map(int, input().split()))[::-1]:
		including_cur = (res+number) * (count+1)
		excluding_cur = res*count + number
		if including_cur >= excluding_cur:
			res += number
			count += 1
		else:
			exclude += number
	print(res*count + exclude)
	