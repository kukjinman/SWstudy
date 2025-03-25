from pprint import pprint

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def BFS(y, x):
    queue = [(y, x)]
    visited[y][x] = 1
    pprint(visited)

    while queue:
        cur_y, cur_x = queue.pop(0)
        print(cur_y, cur_x)

        for i in range(4):
            nx = cur_x + dx[i]
            ny = cur_y + dy[i]

            if nx < 0 or nx >= row or ny < 0 or ny >= col:
                continue
            if visited[ny][nx] == 1:
                # print("visited")
                continue
            if matrix[ny][nx] == 0:
                # print("matrix = 0")
                continue

            queue.append((ny, nx))
            visited[ny][nx] = 1
            # pprint(visited)

    print("BFS 종료")

T = int(input())

for _ in range(T):
    ans = 0
    row, col, K = map(int, input().split())

    matrix = [[0] * row for _ in range(col)]
    visited = [[0] * row for _ in range(col)]

    for _ in range(K):
        x, y = map(int, input().split())
        matrix[y][x] = 1

    pprint(matrix)

    for y in range(col):
        for x in range(row):
            if visited[y][x] != 1 and matrix[y][x] == 1:
                BFS(y, x)
                ans += 1
                # print("x: ", x)
                # print("y: ", y)
                # print("ans: ", ans)

    print(ans)