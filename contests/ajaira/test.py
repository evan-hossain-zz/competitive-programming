#python2
n = int(raw_input())
line = list(raw_input().split(" "))
arr = sorted([int(x) for x in line])
print arr[-1]*arr[-2]