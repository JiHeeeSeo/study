import sys

n = int(input())
l = list(map(int, sys.stdin.readline().split()))

l.sort()
print(l[0], l[-1])

