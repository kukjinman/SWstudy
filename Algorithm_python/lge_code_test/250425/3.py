
#input
# 10
# 0 1 1 2 4 2 1 0 3 3

N = int(input())
arr = list(map(int, input().split()))

def update(arr_, s, e):

    print(arr_[s:e+1])
    print(min(arr_[s:e+1]))
    for i in range(s,e+1):
        arr_[i] -= min(arr_[s:e+1])
    print(arr_[s:e+1])



def search(arr_,s,e):
    print(f"s_ = {s}, e = {e}")
    # 탈출로직 손보기
    if s > e:
        return

    ns = 0
    ne = 0
    start_flag = False
    for i in range(len(arr)):

        if arr[i] != 0 and not start_flag:
            ns = i
            start_flag = True
        elif arr[i] == 0 and start_flag:
            ne = i - 1

            print(f"ns = {ns}, ne = {ne}")
            update(arr_,ns,ne)
            print(arr)
            search(arr[ns:ne+1],0,ne-ns)



search(arr,0,len(arr)-1)
# 마지막에 search와 update 추가

