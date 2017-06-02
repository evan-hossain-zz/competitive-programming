#python2
def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a%b)

if __name__ == "__main__":
    a, b = map(int, raw_input().split())
    print (a*b)/gcd(a, b)
