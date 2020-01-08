import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

d = [ [0 for j in range(1001)] for i in range(1001)]

def combination(n,k):
    global d
    if d[n][k] != 0:
        return d[n][k]
    if k == 0 or n == k:
        return 1

    d[n][k] = ((combination(n-1, k-1) % 10007) + (combination(n-1, k) % 10007)) %10007
    return d[n][k]


n,k = map(int, input().split())
print(combination(n,k))

