
# 1 2 3 4 5 6 7 <- 처음
# 1 2 4 5 6 7 <- 3 빠진 후
# 1 2 4 5 7 <- 6 빠진 후
# 1 4 5 7 <- 2 빠진 후
# 1 4 5  <- 7 빠진 후
# 1 4 <- 5 빠진 후


N, K = map(int, input().split())
arr = [i for i in range(1, N + 1)]

answer = []
idx = 0

for i in range(N):
    idx += K - 1
    idx %= len(arr)
    answer.append(arr.pop(idx))


print("<", end="")
for i in range(N):
    if i == N - 1:
        print(answer[i], end="")
    else:
        print(answer[i], end=", ")
print(">", end="")

