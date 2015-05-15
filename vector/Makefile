CFLAGS = -Wall -g -std=c89
SOURCES = vector.c
OBJECTS = $(SOURCES:.c=.o)

all: vector
vector: $(OBJECTS)
	gcc $(CFLAGS) -o vector vector.o
$(OBJECTS):
	gcc $(CFLAGS) -c $(SOURCES)
clean:
	rm -rf $(OBJECTS) vector
