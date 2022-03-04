
# __init__은 클래스 생성시 호출 함


print("-----------------")
print("#1")

class Person3:
    
    def __init__(self,name,age = 0):
        self.name = name
        self.age = age
    
    def print_info(self):
        print('name:{} age:{}'.format(self.name,self.age))
    
    def walk(self):
        print('walking')
    def speak(self):
        print('speaking')



p3 = Person3('lee')
p3.print_info()


# 상속 

print("-----------------")
print("#2")

class Phone : 
    def call(self, number):
        print(number, '에게 전화를 겁니다.')
    def sendMessage(self, number):
        print(number, '에게 메세지를 보냅니다')


class D_Phone(Phone):
    def take_picture(self):
        print('사진을 찍습니다.')

obj1 = D_Phone()
obj1.take_picture()




# 상속 부모의 생성자 호출 

print("-----------------")
print("#3")

class Phone2 : 
    def __init__(self):
        print('__Phone2_init')
        self.maker = 'LG'
    
    def call(self, number):
        print(number, '에게 전화를 겁니다.')
    def sendMessage(self, number):
        print(number, '에게 메세지를 보냅니다')


class D_Phone2(Phone2):
    def __init__(self):

        #inheritance 상속 부모의 생성자 호출 
        super().__init__()
        print('__Dphone_init')
    
    def take_picture(self):
        print('사진을 찍습니다.')
    def phone_info(self):
        print(f'maker:{self.maker}')

obj2 = D_Phone2()
obj2.phone_info()


# Range의 내부 구성 코드 , __iter__, __next__, StopIteration

print("-----------------")
print("#4")

class CustomRange:
    def __init__(self,start,end):
        self.current = start
        self.end = end
    def __iter__(self):
        print('__iter__ is called')
        return self
    def __next__(self):

        print('__next__ is called')

        if self.current <self.end:
            rvalue = self.current
            self.current +=1
            return rvalue
        else:
            raise StopIteration

for i in CustomRange(1,5):
    print(i)
