CC=g++
VSN=2.1
CFLAGS=-Wall -g
LDFLAGS=
SOURCES=date.cpp gregorian.cpp julian.cpp kattistime.cpp 
OBJECTS=$(SOURCES:.cpp=.o)

all: test_$(VSN)

cprog09lab22a:$(OBJECTS) cprog09lab22a.o
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) cprog09lab22a.o
	./$@ < lab22a.in > ut
	diff lab22a.out ut &

test_date:$(OBJECTS) test_date.h
	cxxtestgen.pl --error-printer -o $@.cpp test_date.h
	make $@.o
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) $@.o


test_$(VSN):$(OBJECTS) test_$(VSN).h
	cxxtestgen.pl --error-printer -o $(VSN).cpp test_$(VSN).h
	make $(VSN).o
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) $(VSN).o

test_valgrind:test_$(VSN)
	valgrind --leak-check=yes ./test_$(VSN)

test_stream:$(OBJECTS) test_stream.o
	$(CC) $(CFLAGS) $(OBJECTS) test_stream.o -o $@

%.o:%.cpp
	$(CC) $(CFLAGS) -c $<

kattis:
	submit.py -p cprog09lab22a kattistime.h kattistime.cpp cprog09lab22a.cpp date.h date.cpp gregorian.h gregorian.cpp julian.h julian.cpp
clean:
	rm *.o test_$(VSN) $(VSN).cpp 
	rm -r test_$(VSN)
	rm -r test_stream
	rm test_date	