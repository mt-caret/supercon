CC := gcc
LD := gcc
CFLAGS := -Wall -g -std=c89

all: clean test_cap test_nocap test_cpp
test_nocap: test_nocap.o
	$(LD) -o $@ $<
test_cap: test_cap.o
	$(LD) -o $@ $<
test_cap.o test_nocap.o:
	$(CC) $(CFLAGS) -c -o $@ $*.c
test_cpp:
	g++ -Wall -g -o $@ $@.cpp
clean:
	rm -rf *.o test_nocap test_cap test_cpp
