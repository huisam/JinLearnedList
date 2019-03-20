import sys
input = sys.stdin.readline

l = int(input().strip())
a = int(input().strip())
b = int(input().strip())
c = int(input().strip())
d = int(input().strip())
first = a // c
second = b // d
if a % c != 0:
    first += 1
if b % d != 0:
    second += 1
cnt = max(first,second)
print(l - cnt)