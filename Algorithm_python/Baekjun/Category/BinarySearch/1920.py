# 4 1 5 2 3 <- arr
# 1 2 3 4 5 <- arr.sort()
# 0 1 2 3 4 <- index

# 1 3 7 9 5
def binary_search(arr, target):
    left = 0
    right = len(arr) - 1

    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1

N = int(input())
arr = list(map(int, input().split()))
M = int(input())
targets = list(map(int, input().split()))

arr.sort()
print(arr)

for target in targets:
    if binary_search(arr, target) != -1:
        print(1)
    else:
        print(0)