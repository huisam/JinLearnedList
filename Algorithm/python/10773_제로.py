import sys
input = sys.stdin.readline

k = int(input().strip())
ans = []
for t in range(0, k):
    now = int(input().strip())
    if now != 0:
        ans.append(now)
    else:
        ans.pop()
print(sum(ans))