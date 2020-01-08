import sys
import heapq
input = sys.stdin.readline

maxInt = 987654321
v,e = map(int,input().split())
start = int(input().strip())
edge = [[] for _ in range(v+1)]
for _ in range(e):
    a,b,c = map(int,input().split())
    edge[a].append((b,c)) 


def dijkstra(start, d):
    d[start] = 0
    q = []
    heapq.heappush(q, (0, start))

    while q:
        dist,now = heapq.heappop(q) # dist에 따른 우선순위큐
        if d[now] < dist: # 유망하지 않으면 버리자
            continue
        for next,bet in edge[now]:
            nextDist = dist + bet
            if d[next] > nextDist: # 거리가 최소로 갱신이되면 푸쉬
                d[next] = nextDist
                heapq.heappush(q, (nextDist, next))
    for i in range(1,v+1):
        if d[i] == maxInt:
            print("INF")
        else:
            print(d[i])

dijkstra(start, [maxInt for i in range(v+1)] )