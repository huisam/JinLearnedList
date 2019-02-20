n = int(input())
Inf = 2000
v = [[False for _ in range(Inf)] for _ in range(Inf)]

def bfs(now, board, cnt):
    q = [(now,board,cnt)]
    while q:
        x,b,c = q.pop(0)
        v[x][b] = True
        if x == n:
            return c
        if x > 0 and x < Inf:
            if not v[x][x]:
                v[x][x] = True
                q.append((x,x,c+1))
            if not v[x-1][b]:
                v[x-1][b] = True
                q.append((x-1,b,c+1))
        if x > 0 and x + b < Inf:
            if not v[x+b][b]:
                v[x+b][b] = True
                q.append((x+b,b,c+1))


print(bfs(1,0,0))
