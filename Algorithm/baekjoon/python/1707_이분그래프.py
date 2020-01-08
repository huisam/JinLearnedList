import sys
sys.setrecursionlimit(10**6)

input = sys.stdin.readline

def dfs(now, color):
    global edge,visit,ans
    for next in edge[now]:
        if visit[next] == 0:
            visit[next] = color
            dfs(next, -color)
        elif visit[next] == visit[now]:
            ans = False
            return

result = []
k = int(input().strip())
for i in range(k):
    v,e = map(int, input().split())
    edge = [[] for _ in range(v+1)]
    visit = [0 for _ in range(v+1)]
    for j in range(e):
        s1,d1 = map(int, input().split())
        edge[s1].append(d1)
        edge[d1].append(s1)
    ans = True
    for j in range(1,v+1):
        if visit[j] == 0:
            visit[j] = 1
            dfs(j,-1)
    if ans:
        result.append("YES")
    else:
        result.append("NO")
print('\n'.join(result))