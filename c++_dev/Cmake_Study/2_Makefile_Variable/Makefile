CC=gcc
CFLAGS=-g -Wall
TARGET=a.out
OBJS=foo.o bar.o main.o
 
$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

foo.o : foo.c
	$(CC) -c -o foo.o foo.c

bar.o : bar.c
	$(CC) -c -o bar.o bar.c

main.o : main.c
	$(CC) -c -o main.o main.c

clean:
	rm $(OBJECT) $(TARGET)