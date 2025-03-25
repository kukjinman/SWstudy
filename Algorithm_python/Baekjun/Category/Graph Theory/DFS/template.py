from pprint import pprint

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def DFS(y, x):
    visited[y][x] = 1
    pprint(visited)
    print(y, x)

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if nx < 0 or nx >= col or ny < 0 or ny >= row:
            continue
        if visited[ny][nx] == 1:
            continue

        DFS(ny, nx)

col, row = map(int, input().split())
matrix = [[0] * row for _ in range(col)]
visited = [[0] * row for _ in range(col)]

for y in range(col):
    for x in range(row):
        if visited[y][x] != 1:
            DFS(y, x)