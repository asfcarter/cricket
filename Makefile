CC=g++
CCW=i586-mingw32msvc-g++
CFLAGS=-Wall -c
CFLAGSW=-D FREEGLUT_STATIC -I/usr/i586-mingw32msvc/include/ -Wall -c
LIBS=-lGL -lglut
LIBSW=-D FREEGLUT_STATIC -I/usr/i586-mingw32msvc/include -lfreeglut_static -lopengl32 -lwinmm -lgdi32
SOURCES=test1.cpp
#SOURCES=main.cpp player.cpp innings.cpp team.cpp 
OBJECTS=$(SOURCES:%.cpp=%.o)
OBJECTSW=$(SOURCES:%.cpp=%.ow)

all: ma ma.exe

ma.exe: $(OBJECTSW)
	$(CCW) $^ -o $@ $(LIBSW)

ma: $(OBJECTS)
	$(CC) $(LIBS) $^ -o $@ 
	
%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@	
	
%.ow: %.cpp	
	$(CCW) $(CFLAGSW) $< -o $@

clean:
	rm -rf *.o *.ow *.exe ma
