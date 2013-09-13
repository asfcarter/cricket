CC=g++
CCW=i586-mingw32msvc-g++
#CFLAGS=-Wall -c
CFLAGS=-Wall -I/usr/include/SDL -c
#CFLAGS=-Wall -Dmain=SDL_main -c
#CFLAGSW=-D FREEGLUT_STATIC -I/usr/i586-mingw32msvc/include/ -Wall -c
#CFLAGSW=-I/usr/i586-mingw32msvc/include/SDL -Wall -c
CFLAGSW=-I/usr/i586-mingw32msvc/include/SDL2 -Dmain=SDL_main -Wall -c
#LIBS=-lGL -lglut
LIBS=-lSDL
#LIBSW=-D FREEGLUT_STATIC -I/usr/i586-mingw32msvc/include -lfreeglut_static -lopengl32 -lwinmm -lgdi32
#LIBSW=-I/usr/i586-mingw32msvc/include/SDL -L -lmingw32 -lSDLmain -lSDL -lwinmm -lgdi32 -mwindows -lm -lopengl32 -glu32 -Wl,-R
LIBSW=-I/usr/i586-mingw32msvc/include/SDL2 -static -L/usr/i586-mingw32msvc/bin -lmingw32 -lSDL2main -lSDL2  -mwindows  -lm -ldinput8 -ldxguid -ldxerr8 -luser32 -lgdi32 -lwinmm -limm32 -lole32 -loleaut32 -lshell32 -lversion -luuid -static-libgcc
SOURCES=test2_sdl2.cpp
#SOURCES=test1.cpp
#SOURCES=main.cpp player.cpp innings.cpp team.cpp 
OBJECTS=$(SOURCES:%.cpp=%.o)
OBJECTSW=$(SOURCES:%.cpp=%.ow)

all: ma.exe

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
