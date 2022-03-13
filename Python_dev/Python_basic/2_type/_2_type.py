
#Numeric Type
# 1 int
a = 100
print('#1 :',type(a))


# 2 float
b = 323.323
print('#2 :',type(b))

# 3 complex

v_complex = 3 + 3j
print('#3 :',type(v_complex))


#Sequence Type

# 4 str
v_str1 = "Niceman" #str
print('#4 :',type(v_str1))


# 5 list
ldata2 = ['kim', 44, 185.2, True]
ldata2
print('#5 :',type(ldata2))

# 6 tuple

# 튜플은 2가지 점을 제외하고는 전반적으로 리스트와 유사함
# 차이점1. 리스트는 []로 감싸지만, 튜플은 ()로 감쌈
#차이점2. 리스트는 요소의 생성, 삭제, 수정이 가능하지만 튜플은 그 값을 바꿀 수 없음

#결론 tuple 사용할 바에 list사용 

tuple1 = ()
tuple2 = (1,)
tuple3 = (1,2,3)
tuple4 = 1,2,3
tuple5 = ("a", "b", ("ab", "cd", ("xyz",)))
print('#6 :',type(tuple5))


# Set Types
# 7 set

# 중복을 허용 하지 않음
# 고유 명사에 사용하기 좋음 (ex : 색, 동물, 등)
# 집합사용 용이 : 합집합, 교집합, 차집합

ex = {1,2,3,4,5}
print('#7 :',type(ex))


# Mapping Type
# key와 value값의 묶음으로 사용
# key값으로 검색 get하기 좋음
# 8 dict
import json

obj = """
{"name":"Wes",
 "places_lived":["United States", "Spain", "Germany"],
 "pet": null,
 "siblings":[{"name":"Scott", "age":25, "pet":"Zuko"},
             {"name":"Katie", "age":33, "pet":"Cisco"}]
}
"""

pcode = json.loads(obj)
print('#8 :',type(pcode))

# 9 numpy.ndarray
import numpy as np
ldata1 = [4,7,5.5,8,10]
arr1 = np.array(ldata1)
arr1

print('#9 :',type(arr1))


# 10 pandas.core.series.Series

import pandas as pd

sdata1 = pd.Series([4,7,-5,2])
#print(sdata1)
print('#10 :',type(sdata1))



# 11 pandas.core.frame.DataFrame
frame = pd.DataFrame(np.random.randn(100,4),
                     index = pd.date_range('1/1/2000', periods = 100, freq = 'W-WED'),
                    columns = ['seoul','busan','incheon','suwon'])

print('#11 :',type(frame))
