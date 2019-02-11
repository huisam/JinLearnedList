import sys
input = sys.stdin.readline
n,m = map(int,input().split())
db = {}
db2 = {}
for i in range(n):
    gp = input().strip()
    k = int(input())
    db[gp] = [input().strip() for j in range(k)]
    db[gp].sort()
for i in range(m):
    name = input().strip()
    a = int(input())
    if a == 1:
        for data in db:
            if name in db[data]:
                print(data)
                break
    else:
        for now in db[name]:
            print(now)
