CFLAGS = -Wall -g -std=c89
SOURCES = test.c
OBJECTS = $(SOURCES:.c=.o)

all: clean test 
test: $(OBJECTS)
	gcc $(CFLAGS) -o test $(OBJECTS)
$(OBJECTS):
	gcc $(CFLAGS) -c $(SOURCES)
clean:
	rm -rf $(OBJECTS) test
