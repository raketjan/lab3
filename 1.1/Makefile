CC=g++
VSN=2.1
CFLAGS=-Wall -g
LDFLAGS=
SOURCES=date.cpp gregorian.cpp kattistime.cpp
OBJECTS=$(SOURCES:.cpp=.o)

all: test_$(VSN)

test_$(VSN):$(OBJECTS) test_$(VSN).h
	cxxtestgen.pl --error-printer -o $(VSN).cpp test_$(VSN).h
	make $(VSN).o
	$(CC) $(CFLAGS) -o test_$(VSN) $(OBJECTS) $(VSN).o

test_valgrind:test_$(VSN)
	valgrind --leak-check=yes ./test_$(VSN)

test_stream:$(OBJECTS) test_stream.o
	$(CC) $(CFLAGS) $(OBJECTS) test_stream.o -o $@

%.o:%.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o test_$(VSN) $(VSN).cpp 
	rm -r test_$(VSN)
	rm -r test_stream	