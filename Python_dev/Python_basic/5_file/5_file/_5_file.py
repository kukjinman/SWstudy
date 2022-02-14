
infile1 = open('Pre1990.txt','r')

sdata1 = {line for line in infile1}
#Pre1990 is the color name which cannot be duplicated. Therefore, set is used.
print("type of sdata1 : ", type(sdata1))

outfile1 = open('Pre1990_copy.txt','w')

outfile1.writelines(list(sdata1))
infile1.close()
outfile1.close()