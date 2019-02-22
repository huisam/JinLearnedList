import sys
import heapq as hq

input = sys.stdin.readline
Inf = 987654321

def dijkstra(start, end):
    d = [Inf for i in range(n+1)]
    d[start] = 0
    pq = []
    hq.heappush(pq, (0, start))
    while pq:
        dist,now = hq.heappop(pq)
        if now == end:
            return dist
        for val,next in b[now]:
            if d[next] > val + dist:
                d[next] = val + dist
                hq.heappush(pq, (val + dist, next))
    return None


n,e = map(int, input().split())
b = [[] for i in range(n+1)]
for i in range(e):
    v1,v2,val = map(int, input().split())
    b[v1].append((val,v2))
    b[v2].append((val,v1))
n1,n2 = map(int, input().split())

n1ToN2 = dijkstra(n1,n2)
if n1ToN2 is None:
    print(-1)
    sys.exit(0)

first = True
second = True

oneToN1 = dijkstra(1, n1)
n2ToN = dijkstra(n2, n)
if oneToN1 is None or n1ToN2 is None:
    first = False

oneToN2 = dijkstra(1, n2)
n1ToN = dijkstra(n1,n)
if oneToN1 is None or n2ToN is None:
    second = False

if first & second:
    ans = n1ToN2 + min(oneToN1 + n2ToN, oneToN2 + n1ToN)
    print(ans)
else:
    if first | second:
        print(-1)
    else:
        if first:
            print(n1ToN2 + oneToN1 + n2ToN)
        else:
            print(n1ToN2 + oneToN2 + n1ToN)
