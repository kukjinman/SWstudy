import sys


def Input_Data():
    readl = sys.stdin.readline
    R, C = map(int, readl().split())
    map_city = [readl().strip() for _ in range(R)]
    return R, C, map_city


dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


def BFS(y, x, target_list):
    for i in target_list:

        queue = [(y, x)]
        visited[y][x] = 1
        i.append('S')
        print(i)

        for _ in i:

            visited = [[0] * (R) for _ in range(C)]

            cur_target = _
            print(f"cur_target: {cur_target}")
            while (queue):
                cur_y, cur_x = queue.pop(0)

                for i in range(4):
                    nx = cur_x + dx[i]
                    ny = cur_y + dy[i]
                    # print(f"ny : {ny} nx : {nx}")
                    if nx < 0 or nx >= R or ny < 0 or ny >= C:
                        continue
                    if visited[ny][nx] == 1:
                        continue
                    if map_city[ny][nx] == '*':
                        continue

                    if map_city[ny][nx] == str(cur_target):
                        print(map_city[ny][nx])
                        break

                    queue.append((ny, nx))
                    visited[ny][nx] = 1


arr = []
search_list = []


def backtracking():
    if len(arr) == max_val:
        # print(arr)
        search_list.append(arr[:])
        # print(search_list)
        return

    for i in range(1, max_val + 1):
        if i not in arr:
            arr.append(i)
            backtracking()
            arr.pop()


sol = -1
# 입력 받는 부분
R, C, map_city = Input_Data()

# 여기서부터 작성

visited = [[0] * (R) for _ in range(C)]

max_val = 0
s_x_idx = 0
s_y_idx = 0
for i in range(C):
    for j in range(R):
        if map_city[i][j] == 'S':
            s_y_idx = i
            s_x_idx = j

        elif map_city[i][j] != '.' and map_city[i][j] != '*':
            max_val += 1

backtracking()
# print(search_list)

BFS(s_y_idx, s_x_idx, search_list)

# 출력하는 부분
print(sol)