

# 1 int
a = 100
print('#1 :',type(a))


# 2 float
b = 323.323
print('#2 :',type(b))


# 3 list
ldata2 = ['kim', 44, 185.2, True]
ldata2
print('#3 :',type(ldata2))


# 4 set
ex = {1,2,3,4,5}
print('#4 :',type(ex))


# 5 numpy.ndarray
import numpy as np
ldata1 = [4,7,5.5,8,10]
arr1 = np.array(ldata1)
arr1

print('#5 :',type(arr1))


# 6 pandas.core.series.Series

import pandas as pd

sdata1 = pd.Series([4,7,-5,2])
#print(sdata1)
print('#6 :',type(sdata1))


# 7 dict
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
print('#7 :',type(pcode))


# 8 pandas.core.frame.DataFrame
frame = pd.DataFrame(np.random.randn(100,4),
                     index = pd.date_range('1/1/2000', periods = 100, freq = 'W-WED'),
                    columns = ['seoul','busan','incheon','suwon'])

print('#8 :',type(frame))
