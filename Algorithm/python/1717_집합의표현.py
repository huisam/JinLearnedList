import sys

sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline

n, m = map(int, input().split())
number = [i for i in range(n + 1)]


def find(num):
    if number[num] == num:
        return num
    else:
        number[num] = find(number[num])
        return number[num]


def merge(num1, num2):
    x = find(num1)
    y = find(num2)

    if x != y:
        number[y] = x


for a in range(m):
    idx, num1, num2 = map(int, input().split())
    if idx == 0:
        merge(num1, num2)
    else:
        x = find(num1)
        y = find(num2)

        if x == y:
            print("yes")
        else:
            print("no")
