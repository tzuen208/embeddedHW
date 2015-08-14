CC      = arm-linux-gnueabihf-gcc
CFLAGS  = -O0 -ggdb -Wall
LDFLAGS = -fno-stack-protector

evaluation: test1 test2 test3
	time -v qemu-arm -L /usr/arm-linux-gnueabihf ./test1
	time -v qemu-arm -L /usr/arm-linux-gnueabihf ./test2
	time -v qemu-arm -L /usr/arm-linux-gnueabihf ./test3

evaluation1: test1
	time -v qemu-arm -L /usr/arm-linux-gnueabihf ./test1

evaluation2: test2
	time -v qemu-arm -L /usr/arm-linux-gnueabihf ./test2

evaluation3: test3
	time -v qemu-arm -L /usr/arm-linux-gnueabihf ./test3

defult: test1 test2 test3

test1: test1.o
	$(CC) -o $@ $^
test2: test2.o
	$(CC) -o $@ $^

test3: test3.o
	$(CC) -o $@ $^

test1.o: test1.c

test2.o: test2.c

test3.o: test3.c
	$(CC) -c $(CFLAGS) $(LDFLAGS) -o $@ $^
	
%.o: %.c
	$(CC) -c $(CFLAGS) $(LDFLAGS) -o $@ $^

clean:
	rm -f test1.o test2.o test3.o test1 test2 test3
