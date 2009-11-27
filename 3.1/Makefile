CC=g++
CFLAGS=-Wall -g

SOURCES=hen.cpp outdoors.cpp witch.cpp container.cpp item.cpp indoors.cpp rum.cpp trollkarl.cpp game.cpp hero.cpp monster.cpp npc.cpp parser.cpp thing.cpp worm.cpp
OBJECTS=$(SOURCES:.cpp=.o)
HEADERS=$(SOURCES:.cpp=.h)

all:supergame

components:place.o actor.o $(OBJECTS) $(HEADERS) place_actor.h Makefile

supergame: components supergame.o
	$(CC) $(CFLAGS) -o $@ place.o actor.o $(OBJECTS) $@.o		

%.o:%.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm *.o supergame