import sys

input = sys.stdin.readline

n, to = map(int, input().split())
stat = [[] for i in range(n)]
ans = 3_000_000

for i in range(n):
    a, b, c = map(int, input().split())
    stat[i] = [a, b, c]

stat = sorted(stat, key=lambda x: x[0])
for i in range(n):
    for j in range(n):
        cnt = 0
        for k in range(n):
            if stat[i][1] >= stat[k][1] and stat[j][2] >= stat[k][2]:
                cnt += 1
            if cnt >= to:
                ans = min(ans, stat[k][0] + stat[i][1] + stat[j][2])
                break

print(ans)
