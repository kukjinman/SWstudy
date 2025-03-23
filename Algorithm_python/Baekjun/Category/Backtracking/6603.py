#
# 7 1 2 3 4 5 6 7
# 8 1 2 3 5 8 13 21 34
# 0

def dfs(arr, result, idx, depth):
    if len(result) == 6:
        # print(result)
        print(' '.join(map(str, result)))
        return
    for i in range(idx, depth):
        result.append(arr[i])
        dfs(arr, result, i+1, depth)
        result.pop()


while True:
    arr = list(map(int, input().split()))
    if arr[0] == 0:
        break
    k = arr[0]
    result = []
    dfs(arr[1:],result, 0, k)
    print()
