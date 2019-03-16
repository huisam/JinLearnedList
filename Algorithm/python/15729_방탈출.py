import sys
input = sys.stdin.readline
n = int(input().strip())
num = list(map(int,input().split()))
ans = 0
for i in range(n):
    if num[i]:
        ans += 1
        for j in range(i+1,i+3):
            if j >= n:
                break
            num[j] ^= 1
print(ans)