import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))

m = int(input())
targets = list(map(int, input().split()))

count ={}
for i in arr:
    if i in count:
        count[i] += 1
    else:
        count[i] = 1

for i in targets:
    if i in count:
        print(count[i], end=' ')
    else:
        print(0, end=' ')








