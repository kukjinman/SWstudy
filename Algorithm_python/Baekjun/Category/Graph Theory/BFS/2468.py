from pprint import pprint

dx = [-1,1,0,0]
dy = [0,0,-1,1]

def search_max():
    max_value = 0
    for y in range(N):
        for x in range(N):
            if matrix[y][x] > max_value:
                max_value = matrix[y][x]
    return max_value

def BFS(y,x, height):

    queue = [(y,x)]
    visited[y][x] = 1

    while queue:
        cur_y,cur_x = queue.pop(0)


        for i in range(4):
            nx = cur_x + dx[i]
            ny = cur_y + dy[i]

            if nx < 0 or nx >= N or ny < 0 or ny >= N:
                continue
            if visited[ny][nx] == 1:
                continue
            if matrix[ny][nx] <= height:
                continue

            queue.append((ny,nx))
            visited[ny][nx] = 1



N = int(input())
matrix = [[0]*(N) for _ in range(N)]

matrix = [list(map(int,input().split())) for _ in range(N)]
# for i in matrix:
#     print(i)
max_num = search_max()

result = 0
for i in range(max_num):
    visited = [[0] * (N) for _ in range(N)]


    cnt = 0
    for y in range(N):
        for x in range(N):
            if matrix[y][x] > i and visited[y][x] == 0:
                BFS(y,x,i)
                cnt += 1
    if cnt > result:
        result = cnt

print(result)
