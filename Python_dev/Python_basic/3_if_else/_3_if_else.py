


# ex 1
score = 88

if score>= 90 : grade = 'A'
elif score >= 80 : grade = 'B'
elif score >= 70 : grade = 'C'
elif score >= 60 : grade = 'D'
else : grade = 'F'
    
print('당신의 학점은 ' , grade , '입니다')


# ex 2
result8 = [i if i%2 == 0 else 10 for i in range(10)]
print(result8)



# ex 3
class CustomRange:
    def __init__(self,start,end):
        self.current = start
        self.end = end
    def __iter__(self):
        return self
    def __next__(self):

# if 문의 : 다음으로 계속 진행된다 c에서 {}의 개념으로 보면됨
        if self.current <self.end:
            rvalue = self.current
            self.current +=1
            return rvalue
        else:
            raise StopIteration
