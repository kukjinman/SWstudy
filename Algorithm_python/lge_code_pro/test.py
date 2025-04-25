

# 파이썬에서 함수 안에서 매개변수 값을 함수 밖에서도 변경하려면 어떻게 해야 해?

# 1. 전역변수 사용하기
# 2. mutable한 객체 사용하기
# 3. return 값으로 변경된 값을 반환하기
# 4. 클래스 사용하기
# 5. closure 사용하기
# 6. decorator 사용하기
# 7. lambda 함수 사용하기
# 8. functools.partial 사용하기
# 9. exec() 함수 사용하기
# 10. eval() 함수 사용하기
# 11. globals() 함수 사용하기
# 12. locals() 함수 사용하기

#
# map = [[0]*5 for _ in range(5)]
#
# def example(map_):
#     map_[0][0] = 1
#     map_[1][1] = 2
#     map_[2][2] = 3
#     map_[3][3] = 4
#     map_[4][4] = 5
#
# example(map)
#
#
#
# print(map[:])
# print(map)

list = [1, 2, 3, 4, 5]

list.sort(reverse=True)
print(list)

dic = {}

dic['my'] = 1
dic['name'] = 2
dic['my'] += 3

print(dic)





