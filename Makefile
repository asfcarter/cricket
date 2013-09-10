CC=g++
CCW=i586-mingw32msvc-g++
CFLAGS=-Wall -c
LIBS=-lGL -lglut
SOURCES=test1.cpp
#SOURCES=main.cpp player.cpp innings.cpp team.cpp 
OBJECTS=$(SOURCES:%.cpp=%.o)
OBJECTSW=$(SOURCES:%.cpp=%.ow)

all: ma

ma.exe: test1.cpp
	$(CCW) -lopengl32 -lglu32 $^ -o $@

ma: $(OBJECTS)
	$(CC) $(LIBS) $^ -o $@

#ma.exe: $(OBJECTSW)	
#	$(CCW) -lglu32 -lopengl32 -lfreeglut $^ -o $@	
	
%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@	
	
%.ow: %.cpp	
	$(CCW)  -lopengl32 -lfreeglut -lglu32 $(CFLAGS) $< -o $@

clean:
	rm -rf *o *ow ma.exe ma

i586-mingw32msvc-g++ test1.cpp -o test1.exe -D FREEGLUT_STATIC -I/usr/i586-mingw32msvc/include/ -lfreeglut_static -lopengl32 -lwinmm -lcrypt32 -lgdi32
