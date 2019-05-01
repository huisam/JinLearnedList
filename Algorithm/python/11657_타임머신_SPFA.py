from collections import deque
import sys

input = sys.stdin.readline
inf = 987654321


def SPFA(start):
    d = [inf for _ in range(n)] # 최소 비용 거리
    on = [False for _ in range(n)] # 큐에 넣었는지 아닌지
    cycle = [0 for _ in range(n)] # 무한으로 cycle이 도는지 아닌지
    d[start] = 0
    on[start] = True
    q = deque([start])
    while q:
        now = q.popleft()
        on[now] = False
        for next, val in edge[now]: # 다음 간선에대해
            if d[next] > d[now] + val: # 갱신할 수 있으면
                d[next] = d[now] + val # 갱신
                if not on[next]: # 큐에 넣었지 않았으면
                    cycle[next] += 1 # cycle체크
                    if cycle[next] >= n: # Node의 개수만큼 큐에 방문했으면
                        print(-1) # 무한 cycle이므로 답을 구할 수 없음
                        return
                    on[next] = True
                    q.append(next) # 큐에 넣기
    for val in d[1:]:
        print(-1) if val == inf else print(val)


n, m = map(int, input().split())
edge = [[] for _ in range(n)]
for _ in range(m):
    u, v, w = map(int, input().split())
    edge[u - 1].append((v - 1, w))
SPFA(0)
