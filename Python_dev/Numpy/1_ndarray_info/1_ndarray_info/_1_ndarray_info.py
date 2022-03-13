
import numpy as np
import numpy.random as npr

a = np.arange(15).reshape(3, 5)
print(a)
print("\n")

# ndarray.shape : 배열의 각 축(axis)의 크기
# (3, 5)

print(" shape : ", a.shape)

#ndarray.ndim : 축의 개수(Dimension)
# 2

print(" ndim : ", a.ndim)

#ndarray.dtype : 각 요소(Element)의 타입
# int64
print(" dtype : ", a.dtype)

#ndarray.itemsize : 각 요소(Element)의 타입의 bytes 크기
# 8

print(" itemsize : ", a.itemsize)

#ndarray.size : 전체 요소(Element)의 개수
# 15


print(" size : ", a.size)


# <class 'numpy.ndarray'>
print(" type : ", type(a))
