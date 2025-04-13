import sys

# def binary_search(arr, target):
#     left = 0
#     right = len(arr) - 1
#
#     while left <= right:
#         mid = (left + right) // 2
#         if arr[mid] == target:
#             return mid
#         elif arr[mid] < target:
#             left = mid + 1
#         else:
#             right = mid - 1
#     return -1
#
# def count_occurrences(arr, target):
#
#     first = binary_search(arr, target)
#     if first == -1:
#         return 0
#
#     count = 1
#     left = first - 1
#     right = first + 1
#
#     while left >= 0 and arr[left] == target:
#         count += 1
#         left -= 1
#
#     while right < len(arr) and arr[right] == target:
#         count += 1
#         right += 1
#
#     return count

def binary_search_10816(arr, target):
    left = 0
    right = len(arr) - 1

    # Find the first occurrence of target
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    first_occurrence = left

    # Find the last occurrence of target
    left = 0
    right = len(arr) - 1

    while left <= right:
        mid = (left + right) // 2
        if arr[mid] <= target:
            left = mid + 1
        else:
            right = mid - 1

    last_occurrence = right

    # Debugging output
    # print("target:", target)
    # print("first_occurrence:", first_occurrence)
    # print("last_occurrence:", last_occurrence)

    return max(0, last_occurrence - first_occurrence + 1)



input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
arr.sort()

# print(arr)

m = int(input())
targets = list(map(int, input().split()))


result = []
for target in targets:
    count = binary_search_10816(arr, target)
    # 시간초과 사례
    # count = count_occurrences(arr, target)
    result.append(count)

print(*result)
