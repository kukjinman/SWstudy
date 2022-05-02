#!/usr/bin/env python
# coding: utf-8

# In[1]:


def recursive(num) :
    if num == 0:
        return 0
    elif num == 1:
        return 1
    return recursive(num-1) + recursive(num -2)
input_num = int(input())
print(recursive(input_num))


# In[ ]:




