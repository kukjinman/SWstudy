import numpy as np

# 1. arange 

print("-----------------")
print("#1")

arr1 = np.arange(10)
print(arr1)


# 2. sqaure

print("-----------------")
print("#2")

arr1 = np.arange(10)
print(np.square(arr1))

# 3. exp

print("-----------------")
print("#3")

print(np.exp(arr1))


# 4. sin

print("-----------------")
print("#4")

print(np.sin(arr1))


# 5. cos


print("-----------------")
print("#5")

print(np.cos(arr1))


# 6. max

print("-----------------")
print("#6")

arr2 = np.array([4,2,1,7,8])
arr3 = np.array([5,1,4,6,9])

print(np.maximum(arr2, arr3))


# 6. modf

print("-----------------")
print("#7")

arr4 = np.array([32.522,74.437,814.888,123.657])

print(np.modf(arr4))
