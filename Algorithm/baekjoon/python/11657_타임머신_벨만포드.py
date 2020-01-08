import sys
input = sys.stdin.readline
inf = 987654321

n, m = map(int, input().split())
edge = []
for _ in range(m):
    f, g, v = map(int, input().split())
    edge.append([f-1,g-1, v])
# 벨만포드 알고리즘 = 시간복잡도 O(VE), 공간복잡도 O(V)
d = [inf for _ in range(n)]
# 자신은 0
d[0] = 0
cycle = False
# 루프 n-1번에 대해서
for i in range(n-1):
    for j in range(m): # 모든 정점에서
        now,next,val = edge[j]
        if d[now] != inf and d[next] > d[now] + val: # 최단 경로가 갱신된다면!
            d[next] = d[now] + val # 갱신
# 음수 사이클 체크
for j in range(m): # 모든 정점에서
    now,next,val = edge[j]
    if d[now] != inf and d[next] > d[now] + val:
            cycle = True
            break

if cycle:
    print(-1)
else:
    for i in range(1,n):
        if d[i] == inf:
            print(-1)
        else:
            print(d[i])