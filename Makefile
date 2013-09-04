CC=g++
CCW=i586-mingw32msvc-g++
CFLAGS=-c -Wall
SOURCES=main.cpp player.cpp innings.cpp team.cpp
OBJECTS=$(SOURCES:%.cpp=%.o)
OBJECTSW=$(SOURCES:%.cpp=%.ow)

all: ma ma.exe

ma: $(OBJECTS)
	$(CC) $^ -o $@

ma.exe: $(OBJECTSW)	
	$(CCW) $^ -o $@	
	
%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@	
	
%.ow: %.cpp	
	$(CCW) $(CFLAGS) $< -o $@

clean:
	rm -rf *o *ow ma.exe ma
