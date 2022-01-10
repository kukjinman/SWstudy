
#실행순서

#4th
a.out : foo.o bar.o main.o
	gcc -o a.out foo.o bar.o main.o
	$(info ************  TEST 4 ************)

#1st
foo.o : foo.c
	gcc -c -o foo.o foo.c
	$(info ************  TEST 1 ************)

#2nd
bar.o : bar.c
	gcc -c -o bar.o bar.c
	$(info ************  TEST 2 ************)

#3rd
main.o : main.c
	gcc -c -o main.o main.c
	$(info ************  TEST 3 ************)


clean:
	rm *.o a.out
	$(info ************  TEST 0 ************)
