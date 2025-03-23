
dx = [-1,1,0,0]
dy = [0,0,-1,1]

def BFS(x,y):

    queue = [(x,y)]
    visited[x][y] = 1
    # print(visited)
    # print(x,y)

    while queue:
        x,y = queue.pop(0)


        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx < 0 or nx >= M or ny < 0 or ny >= N:
                continue
            if visited[nx][ny] == 1:
                continue
            if matrix[nx][ny] == 0:
                continue

            queue.append((nx,ny))
            visited[nx][ny] = 1
            # print(visited)
            # print(nx,ny)

T = int(input())

for _ in range(T):
    ans = 0
    M, N, K = map(int,input().split())
    matrix = [[0]*(N) for _ in range(M)]
    visited = [[0]*(N) for _ in range(M)]

    for _ in range(K):
        a, b = map(int,input().split())
        matrix[a][b] = 1



    for a in range(M):
        for b in range(N):
            if visited[a][b] != 1 and matrix[a][b] == 1:
                BFS(a,b)
                ans += 1

    print(ans)