
#General

print("[General]")
print("--------------------------------------------")

family = ['mother', 'father', 'gentleman', 'sexy lady']

for x in family:        # family의 각 항목 x에 대하여:
    print(x, len(x)) 

print("--------------------------------------------")



#enumerate ex1)
print("[enumerate ex1]")
print("--------------------------------------------")
ldata1 = ['orange','yellow','red']
for i, v in enumerate(ldata1):
    print(i,v,sep=':')
print("--------------------------------------------")


#enumerate ex2)

print("[enumerate ex2]")
print("--------------------------------------------")


result1 = {i:j for i , j in enumerate('teamlab is an academic institude located in South Korea'.split())}
print(result1)
print("--------------------------------------------")


#zip ex1) 
print("[zip ex1]")
print("--------------------------------------------")
ldata1 = [30,20,10,50]
ldata2 = ['kim','lee','choi','oh']
ldata3 = [175,185,165,155]

for i in zip(ldata1, ldata2, ldata3):
    print(i)
print("--------------------------------------------")

#zip ex2) 
print("[zip ex2]")
print("--------------------------------------------")

ldata1 = [30,20,10,50]
ldata2 = ['kim','lee','choi','oh']
ldata3 = [175,185,165,155]

for a,n,h in zip(ldata1, ldata2, ldata3):
    print(f'age:{a}, name:{n}, height:{h}')
print("--------------------------------------------")

#zip ex3) 
print("[zip ex3]")
print("--------------------------------------------")

t1 = (4,5,8)
t2 = (55, 77 , 11)
t3 = (333, 444, 888)

result1 = [x+y+z for x, y,z in zip(t1,t2,t3)]
print(result1)

print("--------------------------------------------")
