import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)


def bfs(start, now, cnt, check):
    q = [[now,cnt,check]]
    while len(q) != 0:
        node = q.pop(0)
        if node[2][node[0]]:
            continue
        else:
            node[2][node[0]] = True
            ans[start] += node[1]
            for next in range(n+1):
                if friend[node[0]][next]:
                    q.append([next, node[1] + 1, node[2]])


n,m = map(int,input().split())
ans = [0 for i in range(n+1)]
friend = [[False for i in range(n+1)] for i in range(n+1)]

for i in range(m):
    f1,f2 = map(int,input().split())
    friend[f1][f2] = True
    friend[f2][f1] = True

for i in range(1,n+1):
    bfs(i, i, 0, [False for i in range(n+1)])

idx = 1
for i in range(1, n+1):
    if ans[i] < ans[idx]:
        idx = i
print(idx)