

# ex 1 - float decimal point 변경

print("-----------------")
print("#1")

obj1 = 20 * 1.5 * 2.01111
name = "kuk jin"

print("Pay for " ,name," : ", '${:,.2f}'.format(obj1)  )
print("Pay for " ,name," : ", '${:,.4f}'.format(obj1)  )

print("Pay for " ,name," : ", '%0.4f' %obj1  )


# ex 2 - 정수 

print("-----------------")
print("#2")


ex_int = 4

print("정수 : %d"  %ex_int)
print("정수 : ", ex_int)

#ex 3 - % print하기
print("-----------------")
print("#3")

print("정수 : %d%%"  %ex_int)

#4 공백 넣기
print("-----------------")
print("#4")
print("%10s 왼쪽에 공백10개" %"안녕!") 
print("%-10s 오른쪽에 공백10개" %"안녕!")
print("%10.3f 소수점 포현" % 3.141592)


