import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(0,1,50)

y1 = np.cos(4*np.pi*x)
y2 = np.cos(4*np.pi*x)*np.exp(-2*x)

# 3 x 3
# left to right --> row

# 1 2 3
# 4 5 6
# 7 8 9

#subplot parameter meaning
# 1st : column division
# 2nd : row division 
# 3rd : position


# 3x3 division box and assign to 1st position
plt.subplot(3,3,1)
plt.plot(x,y1,'r-*',lw=1)

# grid graph뒤의 격자
#plt.grid(True)  
plt.ylabel(r'$sin(4 \pi x)$')
plt.axis([0,1,-1.5,1.5])


# 3x3 division box and assign to 3rd position

plt.subplot(3,3,3)
plt.plot(x,y2,'b--o',lw=1)

plt.grid(True)
plt.xlabel('x')
plt.ylabel(r'$ e^{-2x} sin(4\pi x) $')
plt.axis([0,1,-1.5,1.5])


# 3x1 division box and assign to 2nd position

plt.subplot(3,1,2)

# 3x3 division box and assign to 8th position

plt.subplot(3,3,8)


#plt.tight_layout()
plt.show()