#!/usr/bin/env python
# coding: utf-8

# In[3]:


num = int(9)
a = []

for i in range(num) :
    a.append(int(input()))
    
print(max(a))
print(a.index(max(a))+1)


# In[ ]:




