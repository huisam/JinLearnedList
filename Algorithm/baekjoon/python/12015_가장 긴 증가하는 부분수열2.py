import sys,bisect
input = sys.stdin.readline

n = int(input())
a = list(map(int,input().split()))
d = [a[0]]

for i in range(1,n):
    if d[len(d)-1] < a[i]:
        d.append(a[i])
    else:
        idx = bisect.bisect(d,a[i])
        d[idx] = a[i]
print(len(d))

