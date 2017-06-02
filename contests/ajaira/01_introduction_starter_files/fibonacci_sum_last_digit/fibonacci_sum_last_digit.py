#python2
m = 10
def mat_mul(mata, matb):
    n = len(mata)
    ret = list()
    for i in range(n):
        ret.append([0]*n)
    for i in range(n):
        for j in range(n):
            for k in range(n):
                try:
                    ret[i][j] += mata[i][k] * matb[k][j]
                    ret[i][j] %= m
                except:
                    pass
    return ret

def mat_expo(mat, p):
    if p == 0:
        return mat
    n = len(mat)
    xx = list()
    for i in range(n):
        xx.append([0]*n)
        xx[i][i] = 1
    power = mat[:]
    while p > 0:
        if p % 2 == 1:
            xx = mat_mul(xx, power)
        power = mat_mul(power, power)
        p /= 2
    return xx

def get_nth_fibo(n):
    mat = [[1, 1], [1, 0]]
    base = [[1], [0]]
    if n < 3:
        return (n != 0) % m
    else:
        res = mat_mul(mat_expo(mat, n - 1), base)
        return res[0][0] % m

if __name__ == '__main__':
    n = int(raw_input())
    print (get_nth_fibo(n+2)-1+10)%10

