import sys
input = sys.stdin.readline
print = sys.stdout.write
sys.setrecursionlimit(10**6)


def dfs(x):
    if check[x]:
        return
    global ans
    check[x] = True
    nums = db[x]
    for i in nums:
        if not check[i]:
            dfs(i)
    sys.stdout.write(str(x) + " ")


st = input()
now = st.split()
n = int(now[0])
m = int(now[1])
db = [[] for i in range(n+1)]
check = [False for i in range(n+1)]
for i in range(m):
    st = input().split()
    x = int(st[0])
    y = int(st[1])
    db[y].append(x)

for i in range(1, n+1):
    dfs(i)

