from collections import deque
import sys
input = sys.stdin.readline
inf = 987654321
def SPFA(start):
    d = [inf for _ in range(n)]
    on = [False for _ in range(n)]
    d[start] = 0
    on[start] = True
    q = deque([start])
    while q:
        now = q.popleft()
        on[now] = False
        for next, val in edge[now]:
            if d[next] > d[now] + val:
                d[next] = d[now] + val
                if not on[next]:
                    on[next] = True
                    q.append(next)
    for val in d:
        print("INF") if val == inf else print(val)

n,m = map(int, input().split())
k = int(input().strip())
edge = [[] for _ in range(n)]
for _ in range(m):
    u,v,w = map(int, input().split())
    edge[u-1].append((v-1,w))
SPFA(k-1)