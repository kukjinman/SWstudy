import sys



def find_closest_pair(arr):
    left = 0
    right = len(arr) - 1
    min_diff = sys.maxsize
    closest_pair = (arr[left], arr[right])

    while left < right:
        cur_sum = arr[left] + arr[right]
        if abs(cur_sum) < min_diff:
            min_diff = abs(cur_sum)
            closest_pair = (arr[left], arr[right])

        if cur_sum < 0:
            left += 1
        elif cur_sum > 0:
            right -= 1
        else:
            return closest_pair
    return closest_pair

n = int(input())
arr = list(map(int, input().split()))
arr.sort()

result_left, result_right = find_closest_pair(arr)
print(result_left, result_right)

