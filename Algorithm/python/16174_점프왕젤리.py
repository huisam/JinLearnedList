import sys
input = sys.stdin.readline


def bfs(start):
    q = [start]
    check = [[False for i in range(n)] for i in range(n)]
    while q:
        now = q.pop(0)
        y = now[0]
        x = now[1]
        if x < 0 or y < 0 or x >= n or y >= n:
            continue
        if x == n-1 and y == n-1:
            print("HaruHaru")
            return
        if check[y][x]:
            continue
        else:
            check[y][x] = True
            idx = area[y][x]
            q.append([y + idx, x])
            q.append([y, x + idx])
    print("Hing")


n = int(input())
area = [[] for i in range(n)]
ans = None
for i in range(n):
    area[i] = list(map(int,input().split()))

bfs([0,0])
