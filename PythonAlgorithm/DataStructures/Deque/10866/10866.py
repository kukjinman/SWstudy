#!/usr/bin/env python
# coding: utf-8

# In[11]:


from collections import deque
import sys

N = input();

dq = deque()

for i in range(N) :
    Order = list(input().split())
    
    if Order[0] == "push_front" :
        dq.appendleftl(Order[1])
        
    elif Order[0] == "push_back" :
        dq.append(Order[1])
    
    elif Order[0] == "pop_front" :
        if len(dq) == 0 :
            print(-1)
        else :
            print(dq.popleft())
            
    elif Order[0] == "push_back" :
        if len(dq) == 0 :
            print(-1)
        else :
            print(dq.pop())
        
        
    elif Order[0] == "size" :
        print(len(dq))
        
        
        
    elif Order[0] == "empty" :
        if len(dq) == 0 :
            print(1)
        else : 
            print(0)
        
        
    elif Order[0] == "front" :
        
        if len(dq) == 0 :
            print(-1)
        else : 
            print(dq[0])
        
        
    elif Order[0] == "back" :
        if len(dq) == 0 :
            print(-1)
        else : 
            print(dq[len(dq) -1])
        
    


# In[ ]:





# In[ ]:




