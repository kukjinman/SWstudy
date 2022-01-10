CC=gcc
TARGET=a.out
OBJS=foo.o bar.o main.o
 
# $@ -> 현재 target 이름
$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)
	$(info ************  TEST 4 ************)
	$(info $(OBJS) $(CC) -o $@ $(OBJS))

#실행되지 않는 라인들 info message가 뜨지 않음
foo.o : foo.c
	$(CC) -c -o foo.o foo.c
	$(info ************  TEST 1  ************)
bar.o : bar.c
	$(CC) -c -o bar.o bar.c
	$(info ************  TEST 2 ************)
main.o : main.c
	$(CC) -c -o main.o main.c
	$(info ************  TEST 3 ************)
#------------------------------------------------

clean:
	rm $(OBJECT) $(TARGET)
	$(info ************  TEST 0 ************)
