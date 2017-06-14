import bisect

def gen_cum_sum(X):
	ret = [0]*(len(X)+1)
	for i in range(len(X)):
		ret[i] = X[i] + ret[i-1]
	return ret

test = int(input())
for t in range(test):
	p, q, r = map(int, input().split())
	A = sorted(map(int, input().split()))
	B = sorted(map(int, input().split()))
	C = sorted(map(int, input().split()))
	cum_A, cum_C = gen_cum_sum(A), gen_cum_sum(C)
	res = 0
	mod = 1000000007
	for y in B:
		a_indx = bisect.bisect_right(A, y)
		c_indx = bisect.bisect_right(C, y)
		res += c_indx * y * cum_A[a_indx-1]
		res += a_indx * y * cum_C[c_indx-1]
		res += y**2 * a_indx * c_indx
		res += cum_A[a_indx-1] * cum_C[c_indx-1]
		res %= mod
	print(res)


