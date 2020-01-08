import sys
input = sys.stdin.readline

n = int(input().strip())
alpa = [input().strip() for _ in range((n-1)*2)]
first = []
second = []
for idx in alpa:
    if len(idx) == 1:
        first.append(idx)
    if len(idx) == n-1:
        second.append(idx)
db = set()
for i in first:
    for j in second:
        db.add(i + j)
        db.add(j + i)
db = list(db)
ix = 0
ans = ''
while(len(ans) != 2*(n-1)):
    ans = ''
    want = db[ix]
    a = {i:True for i in range(1, n)}
    for idx in alpa:
        find = False
        if a[len(idx)]: # p테스트
            for i in range(1, n):
                if idx == want[:i]:
                    a[len(idx)] = False
                    ans += 'P'
                    find = True
                    break
        if not find:
            for i in range(0, n):
                if idx == want[i:n]:
                    ans += 'S'
                    break
    ix += 1
print(want)
print(ans)
