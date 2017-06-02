test = int(input())
while test > 0:
	head = 0
	tail = 0
	valid = True
	input()
	for x in input():
		head += x == 'H'
		tail += x == 'T'
		if head < tail or head > tail+1:
			valid = False
			break
	if valid and head == tail:
		print('Valid')
	else:
		print('Invalid')
	test -= 1