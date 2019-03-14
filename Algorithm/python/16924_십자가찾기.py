import sys
input = sys.stdin.readline
n,m = map(int, input().split())
arr = [list(input().strip()) for _ in range(n)]
cnt = [[0 for _ in range(m)] for __ in range(n)]
idx = max(n,m) // 2
dx = [-1,1,0,0]
dy = [0,0,1,-1]
ans = 0
ansList = []
def bfs(x,y):
    global arr,cnt,ans,ansList
    nowList = []
    for i in range(1,idx+1):
        for j in range(4):
            nx = x + dx[j] * i
            ny = y + dy[j] * i
            if nx >= n or nx < 0 or ny >= m or ny < 0 or arr[nx][ny] == '.':
                break
            nowList.append((nx,ny))
        else:
            for nx,ny in nowList:
                cnt[nx][ny] += 1
            cnt[x][y] += 1
            ans += 1
            ansList.append((x+1,y+1,i))
            nowList.clear()
            continue
        break

for i in range(n):
    for j in range(m):
        if arr[i][j] == '*':
            bfs(i,j)
for i in range(n):
    for j in range(m):
        if arr[i][j] == '*' and cnt[i][j] == 0:
            print(-1)
            sys.exit(0)
print(ans)
for now in ansList:
    print(now[0],now[1],now[2])