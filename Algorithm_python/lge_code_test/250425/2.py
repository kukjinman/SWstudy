
# input
# 5 6
# 0 0 0 0 1 0
# 0 0 0 0 0 0
# 0 0 1 1 0 0
# 0 0 1 1 0 0
# 0 0 0 0 0 0
# 0 1 1 4
# 2
# 2 3

Y, X = map(int, input().split())
matrix = [list(map(int, input().split())) for _ in range(Y)]
visited = [[0] * X for _ in range(Y)]
sy, sx, ey, ex = map(int, input().split())
p = int(input())
b = list(map(int, input().split()))

# for _ in matrix:
#     print(_)
# print(sy, sx, ey, ex)
# print(p)
# print(b)

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]
matrix[ey][ex] = 'E'

for _ in matrix:
    print(_)

def BFS(y, x):
    queue = [(y, x)]
    visited[y][x] = 1

    while queue:
        cur_y, cur_x = queue.pop(0)

        for j in b:
            for i in range(4):
                ny = cur_y + dy[i] * j
                nx = cur_x + dx[i] * j
                if ny < 0 or ny >= Y or nx < 0 or nx >= X:
                    continue
                if visited[ny][nx] == 1:
                    continue

                wall_flag = False
                for k in range(j):
                    if matrix[ny-k][nx] == 1:
                        wall_flag = True

                    if matrix[ny][nx-k] == 1:
                        wall_flag = True

                if wall_flag:
                    continue

                if matrix[ny][nx] == 'E':
                    print("도착")


                print(f"ny = {ny}, nx = {nx}, j = {j}")

                queue.append((ny, nx))
                visited[ny][nx] = 1

                for _ in visited:
                    print(_)
                print("-------------------------------")

BFS(sy, sx)







