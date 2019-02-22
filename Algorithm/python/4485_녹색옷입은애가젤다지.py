import sys
import heapq as hq
input = sys.stdin.readline

dx = [0,0,1,-1]
dy = [1,-1,0,0]
Inf = 987654321


def search(b):
    ans = 0
    d = [[Inf for _ in range(n)] for _ in range(n)]
    pq = []
    d[0][0] = 0
    hq.heappush(pq, (b[0][0], 0, 0))
    while pq:
        cost,x,y = hq.heappop(pq)
        # 종료조건
        if x == n-2 and y == n-1:
            ans = cost
            break
        elif x == n-1 and y == n-2:
            ans = cost
            break
        # 큐에 넣기
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or ny < 0 or nx >= n or ny >= n:
                continue
            # Dijkstra
            if d[nx][ny] > cost + b[nx][ny]:
                hq.heappush(pq, (cost + b[nx][ny], nx, ny))
                d[nx][ny] = cost + b[nx][ny]
    ans += b[n-1][n-1]
    return str(ans)


t = 0
while True:
    n = int(input().strip())
    if n == 0:
        break
    t += 1
    b = [list(map(int, input().split())) for i in range(n)]
    print("Problem", str(t) + ":", search(b))
