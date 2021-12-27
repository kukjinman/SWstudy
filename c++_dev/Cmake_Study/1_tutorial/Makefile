a.out : foo.o bar.o main.o
	gcc -o a.out foo.o bar.o main.o
foo.o : foo.c
	gcc -c -o foo.o foo.c

bar.o : bar.c
	gcc -c -o bar.o bar.c
main.o : main.c
	gcc -c -o main.o main.c
clean:
	rm *.o a.out