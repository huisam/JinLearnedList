import sys
input = sys.stdin.readline

maps = [[0 for _ in range(101)]for _ in range(101)]

dx = [0,-1,0,1]
dy = [1,0,-1,0]

def dragonCurve(x,y,d,g):
    q = [d]
    if d + 1 > 3:
        q.append(0)
    else:
        q.append(d+1)
    maps[x][y] = 1
    nx = x + dx[d]
    ny = y + dy[d]
    maps[nx][ny] = 1

    idx = 1
    for i in range(g):
        for j in range(idx, len(q)):
            nx += dx[q[j]]
            ny += dy[q[j]]
            maps[nx][ny] = 1
        for k in range(len(q)-1, -1,-1):
            if q[k] + 1 > 3:
                q.append(0)
            else:
                q.append(q[k] + 1)
        idx *= 2



k = int(input().strip())
for i in range(k):
    x,y,d,g = map(int, input().split())
    dragonCurve(y,x,d,g)
ans = 0
for i in range(0,100):
    for j in range(100):
        if maps[i][j] == 1 and maps[i+1][j] == 1 and maps[i][j+1] == 1 and maps[i+1][j+1] == 1:
            ans += 1
print(ans)