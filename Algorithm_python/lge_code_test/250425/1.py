import sys

# input
# ()[{}]
# output
# 3

# input
# ()[{{]
# output
# -1

a = input()
stk = []

def solve():
    stk = []
    for i in range(len(a)):
        ch = a[i]
        if ch == '(' or ch == '{' or ch == '[':
            stk.append(ch)
        else:
            stk.pop()

    if not stk:
        return 1
    else:
        return 0

ans  = solve()
print(ans)

