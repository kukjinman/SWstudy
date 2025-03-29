from pprint import pprint

dx = [-1,1,0,0]
dy = [0,0,-1,1]

def BFS(y,x):

    queue = [(y,x)]
    visited[y][x] = 1
    pprint(visited)
    print(y,x)

    while queue:
        cur_x,cur_y = queue.pop(0)


        for i in range(4):
            nx = cur_x + dx[i]
            ny = cur_y + dy[i]

            if nx < 0 or nx >= row or ny < 0 or ny >= col:
                continue
            if visited[ny][nx] == 1:
                continue

            queue.append((ny,nx))
            visited[ny][nx] = 1
            pprint(visited)
            print(ny,nx)


col, row = map(int,input().split())
matrix = [[0]*(row) for _ in range(col)]
visited = [[0]*(row) for _ in range(col)]

for y in range(col):
    for x in range(row):
        if visited[y][x] != 1:
            BFS(y,x)
