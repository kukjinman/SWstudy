from pprint import pprint

dx = [-1,1,0,0]
dy = [0,0,-1,1]

def BFS(y,x):

    queue = [(y,x)]
    visited[y][x] = 1

    while queue:
        cur_y,cur_x = queue.pop(0)

        # print("cur : ",cur_y,cur_x)

        for i in range(4):
            nx = cur_x + dx[i]
            ny = cur_y + dy[i]

            if nx < 0 or nx >= row or ny < 0 or ny >= col:
                continue
            if visited[ny][nx] == 1:
                continue
            if matrix[ny][nx] == 0:
                continue

            queue.append((ny,nx))
            visited[ny][nx] = 1
            matrix[ny][nx] = matrix[cur_y][cur_x] + 1

            # for i in visited:
            #     print(i)
            # print("next : ",ny,nx)


col, row = map(int,input().split())

matrix = [[0]*(row) for _ in range(col)]
visited = [[0]*(row) for _ in range(col)]

matrix = [list(map(int,input())) for _ in range(col)]


for y in range(col):
    for x in range(row):
        # print(y,x)
        if visited[y][x] != 1 and matrix[y][x] == 1:
            # print(y,x)
            BFS(y,x)


print(matrix[col-1][row-1])