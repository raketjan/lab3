CC=g++
VSN=1.1
CFLAGS=-Wall -g
LDFLAGS=
SOURCES=date.cpp gregorian.cpp julian.cpp kattistime.cpp
OBJECTS=$(SOURCES:.cpp=.o)

all: test_$(VSN)

test_$(VSN):$(SOURCES) test_$(VSN).h
	cxxtestgen.pl --error-printer -o $(VSN).cpp test_$(VSN).h
	$(CC) $(CFLAGS) -o test_$(VSN) $(SOURCES) $(VSN).cpp
	./test_$(VSN)

test_valgrind:test_$(VSN)
	valgrind --leak-check=yes ./test_$(VSN)

clean:
	rm *.o test_$(VSN) $(VSN).cpp 
	rm -r test_$(VSN)