import sys

input = sys.stdin.readline

n,m = map(int, input().split())
db = {}
db2 = {}
for i in range(n):
    now = input().strip()
    db[now] = 1
for i in range(m):
    now = input().strip()
    if db.get(now):
        db2[now] = 1
ans = sorted(db2.keys())
print(len(ans))
for i in ans:
    print(i)