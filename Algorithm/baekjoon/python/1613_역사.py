import sys
input = sys.stdin.readline

n,a = map(int, input().split())
edge = [[0 for _ in range(n+1)] for _ in range(n+1)]
for _ in range(a):
    f,t = map(int, input().split())
    edge[f][t] = -1
    edge[t][f] = 1

for k in range(1, n+1):
    for i in range(1, n+1):
        for j in range(1, n+1):
            if edge[i][k] != 0 and edge[i][k] == edge[k][j]:
                edge[i][j] = edge[i][k]

s = int(input().strip())
ans = []
for _ in range(s):
    be,af = map(int, input().split())
    ans.append(str(edge[be][af]))
print('\n'.join(ans))