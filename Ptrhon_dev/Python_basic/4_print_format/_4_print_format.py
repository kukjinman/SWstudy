

# ex 1 - float decimal point 변경

obj1 = 20 * 1.5 * 2.01111
name = "kuk jin"

print("Pay for " ,name," : ", '${:,.2f}'.format(obj1)  )
print("Pay for " ,name," : ", '${:,.4f}'.format(obj1)  )
