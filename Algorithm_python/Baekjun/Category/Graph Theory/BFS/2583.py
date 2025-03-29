from pprint import pprint

dx = [-1,1,0,0]
dy = [0,0,-1,1]

def BFS(y,x):

    space = 1
    queue = [(y,x)]
    visited[y][x] = 1

    while queue:
        cur_y,cur_x = queue.pop(0)


        for i in range(4):
            nx = cur_x + dx[i]
            ny = cur_y + dy[i]

            if nx < 0 or nx >= row or ny < 0 or ny >= col:
                continue
            if visited[ny][nx] == 1:
                continue
            if matrix[ny][nx] == 1:
                continue

            queue.append((ny,nx))
            visited[ny][nx] = 1
            space += 1

    return space

col, row, K = map(int,input().split())

matrix = [[0]*(row) for _ in range(col)]
visited = [[0]*(row) for _ in range(col)]

for i in range(K):
    x1,y1,x2,y2 = map(int,input().split())
    for y in range(y1,y2):
        for x in range(x1,x2):
            matrix[y][x] = 1

cnt = 0
space_list = []
for y in range(col):
    for x in range(row):
        if visited[y][x] != 1 and matrix[y][x] != 1:
            space = BFS(y,x)
            # print(space)
            cnt += 1
            space_list.append(space)

print(cnt)
space_list.sort()
print(' '.join(map(str,space_list)))