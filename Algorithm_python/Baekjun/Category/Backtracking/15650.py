
n,m= map(int,input().split())

arr = []

def dfs(depth):
    if len(arr) == m:
        print(' '.join(map(str,arr)))
        return
    for i in range(depth,n+1):
        if i not in arr:
            arr.append(i)
            dfs(i+1)
            arr.pop()

dfs(1)