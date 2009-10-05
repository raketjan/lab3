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

test_cxx:$(OBJECTS)
	cxxtestgen.pl --error-printer -o $(VSN).cpp test_$(VSN).h
	$(CC) $(CFLAGS) -o test_$(VSN) $(SOURCES) $(VSN).cpp

test_valgrind:test_$(VSN)
	valgrind --leak-check=yes ./test_$(VSN)


test_stream:$(OBJECTS) test_stream.o
	$(CC) $(CFLAGS) $(OBJECTS) test_stream.o -o $@

%.o:%.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o test_$(VSN) $(VSN).cpp 
	rm -r test_$(VSN)