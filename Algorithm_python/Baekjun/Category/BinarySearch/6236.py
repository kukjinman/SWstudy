
# (1) 500원 인출
# 100원 사용 → 400원 남음 → 400원 사용 → 0원 남음 → 다음에 낼 돈이 없다.
# (2) 500원 인출
# 300원 사용 → 200원 남음 → 100원 사용 → 100원 남음 → 다음에 낼 돈이 부족하다.
# (3) 남은 100원 입금, 500원 인출
# 500원 사용 → 0원 남음 → 다음에 낼 돈이 없다.
# (4) 500원 인출
# 101원 사용 → 399원 남음 → 다음에 낼 돈이 부족하다.
# (5) 남은 399원 입금, 500원 인출
# 400원 사용 → 100원 남음


def binary_search(arr):
    left = max(arr)
    right = sum(arr)

    while left <= right:
        mid = (left + right) // 2
        cash = mid
        count = 1
        # print("left:", left)
        # print("right:", right)
        # print("mid:", mid)
        for i in arr:
            if cash < i:
                count += 1
                cash = mid
            cash -= i

        if count > m:
            left = mid + 1
        else:
            right = mid - 1
    #     print("count:", count)
    #     print("---------------------")
    #
    # print("count:", count)
    # print("mid:", mid)
    return mid



n, m = map(int, input().split())
arr = []
for i in range(n):
    arr.append(int(input()))


result = binary_search(arr)
print(result)

