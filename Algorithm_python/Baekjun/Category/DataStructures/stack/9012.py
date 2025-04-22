
T = int(input())

for i in range(T):
    S = input()
    stack = []
    result = True

    for char in S:
        if char == '(':
            stack.append('(')
        else:
            if not stack:
                result = False
                break
            stack.pop()

    if result and not stack:
        print("YES")
    else:
        print("NO")