import random

N = 10


def binary_search_lower_bound(array, start, end, val):
    while start < end:
        mid = (start + end) // 2
        if array[mid] < val:
            start = mid + 1
        else:
            end = mid
    return end


def binary_search_upper_bound(array, start, end, val):
    while start < end:
        mid = (start + end) // 2
        if array[mid] <= val:
            start = mid + 1
        else:
            end = mid
    return end


if __name__ == "__main__":
    array = [random.randrange(0, 10) for i in range(N)]
    array.sort()
    print(array)
    print(binary_search_lower_bound(array, 0, N - 1, 5))
    print(binary_search_upper_bound(array, 0, N - 1, 5))
