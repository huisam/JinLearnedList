import sys
import heapq
input = sys.stdin.readline
a = []
n = int(input())
ans = ""
for i in range(n):
    now = int(input())
    if now == 0:
        if len(a) == 0:
            ans += "0\n"
        else:
            ans += str(-heapq.heappop(a)) + "\n"
    else:
        heapq.heappush(a, -now)
sys.stdout.write(ans)