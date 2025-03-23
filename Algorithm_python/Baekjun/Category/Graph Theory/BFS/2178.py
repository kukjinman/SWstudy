
dx = [-1,1,0,0]
dy = [0,0,-1,1]

def BFS(x,y):

    queue = [(x,y)]
    visited[x][y] = 1
    print(visited)
    print(x,y)

    while queue:
        x,y = queue.pop(0)


        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx < 0 or nx >= M or ny < 0 or ny >= N:
                continue
            if visited[nx][ny] == 1:
                continue

            queue.append((nx,ny))
            visited[nx][ny] = 1
            print(visited)
            print(nx,ny)


M, N = map(int,input().split())
matrix = [[0]*(N) for _ in range(M)]
visited = [[0]*(N) for _ in range(M)]

for a in range(M):
    for b in range(N):
        if visited[a][b] != 1:
            BFS(a,b)
