import sys

sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline


def quickSort(left, right):
    if left >= right:
        return
    l = left
    r = right
    mid = arr[(l + r) // 2]
    while True:
        while arr[l] < mid:
            l += 1
        while arr[r] > mid:
            r -= 1
        if l >= r:
            break
        temp = arr[l]
        arr[l] = arr[r]
        arr[r] = temp
    quickSort(left, l - 1)
    quickSort(r + 1, right)


n = int(input().strip())
arr = list()
for i in range(n):
    arr.append(int(input().strip()))
quickSort(0, n - 1)
print('\n'.join(str(x) for x in arr))