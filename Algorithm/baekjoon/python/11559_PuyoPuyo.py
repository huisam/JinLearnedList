import sys
from collections import deque
input = sys.stdin.readline

dx = [-1,1,0,0]
dy = [0,0,-1,1]

# bfs 탐색시, 뿌실 수 있으면 뿌시고 값을 True로 리턴
def bfs(check, x, y, idx):
    global arr
    q = deque()
    q.append((x,y))
    breakList = [(x,y)]
    cnt = 1
    while q:
        nowX,nowY = q.popleft()
        for i in range(4):
            nx = nowX + dx[i]
            ny = nowY + dy[i]
            if nx >= 12 or nx < 0 or ny >= 6 or ny < 0 or check[nx][ny]:
                continue
            if arr[nx][ny] == idx and not check[nx][ny]:
                check[nx][ny] = True
                cnt += 1
                q.append((nx,ny))
                breakList.append((nx,ny))
    if cnt >= 4:
        for nx,ny in breakList:
            arr[nx][ny] = '.'
        return True
    else:
        return False


def detect():
    global arr,ans
    check = [[False for _ in range(6)] for __ in range(12)]
    find = False
    for i in range(12):
        for j in range(6):
            if not check[i][j] and arr[i][j] != '.':
                check[i][j] = True
                find |= bfs(check, i, j, arr[i][j]) # or연산을 통해 하나라도 뿌시면 true
    if find:
        ans += 1 # 참이면 횟수에 추가!
    return find

def down():
    global arr
    for j in range(6):
        cnt = 0
        for i in range(12):
            if arr[i][j] == '.':
                cnt += 1
            else:
                arr[i-cnt][j] = arr[i][j]
        for i in range(12-cnt, 12):
            arr[i][j] = '.'


arr = [[] for _ in range(12)]
for i in range(11,-1,-1):
    arr[i] = list(input().strip())

ans = 0
while detect(): # 검사하고 뿌시자
    down() # 뿌시면 내려야지!
print(ans)