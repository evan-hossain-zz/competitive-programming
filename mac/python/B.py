def solution(A):
	temp = A[:]
	temp.sort()
	l = None
	r = None
	for i in range(0, len(A)):
		if A[i] != temp[i]:
			l = i
			break

	for i in range(len(A)-1, 0, -1):
		if A[i] != temp[i]:
			r = i
			break

	if l == None:
		return 0
	return r-l+1


print solution([1, 2, 6, 5, 5, 8, 9])

print solution([1, 2, 5, 5, 6, 8, 9])

print solution([5, 6, 7, 1])

print solution([4, 3, 4])

print solution([2]*100000)