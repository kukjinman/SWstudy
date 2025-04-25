import sys

# input
# ()[{}]
# output
# 3

# input
# ()[{{]
# output
# -1

a = input().strip()
# print(a)
idx_a = 0
idx_b = 0
idx_c = 0
ans = 0


def solve():
    global idx_a, idx_b, idx_c
    tmp_max = 0
    cur_max = 0
    stk = []
    # print(len(a))
    for i in range(len(a)):
        ch = a[i]
        # print(ch)
        if ch == '(':
            stk.append(ch)
            idx_a = i
        elif ch == '{':
            stk.append(ch)
            idx_b = i
        elif ch == '[':
            stk.append(ch)
            idx_c = i
        else:
            if ch == ')':
                # print(stk[idx_a])
                #stk[-1]말고 idx_a를 쓴거 같은데 기억이 안남.. 그래서 틀린듯
                if stk[-1] == '(':
                    cur_max = i - idx_a
                    stk.pop()
            elif ch == '}':
                if stk[-1] == '{':
                    cur_max = i - idx_b
                    stk.pop()
            elif ch == ']':
                if stk[-1] == '[':
                    cur_max = i - idx_c
                    stk.pop()
            else:
                # print("exit")
                return -1



    if tmp_max < cur_max:
        tmp_max = cur_max
    # print(stk)
    if not stk:
        return tmp_max
    else:
        return -1

ans  = solve()
print(ans)

