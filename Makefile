CC=g++
CCW=i586-mingw32msvc-g++

OBJECTS=$(SOURCES:%.cpp=%.o)
OBJECTSW=$(SOURCES:%.cpp=%.ow)

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@	
	
%.ow: %.cpp	
	$(CCW) $(CFLAGSW) $< -o $@

CFLAGS=-std=c++0x -Wall -I/usr/local/include/SDL2 -c


#CFLAGS=-Wall -c
#CFLAGS=-Wall -Dmain=SDL_main -c
#CFLAGSW=-D FREEGLUT_STATIC -I/usr/i586-mingw32msvc/include/ -Wall -c
#CFLAGSW=-I/usr/i586-mingw32msvc/include/SDL -Wall -c
CFLAGSW=-I/usr/i586-mingw32msvc/include/SDL2 -Dmain=SDL_main -Wall -c
#LIBS=-lGL -lglut
LIBS=-L/usr/local/lib -lSDL2 -lGL -lSDL2_image -lSDL2_ttf 
#LIBSW=-D FREEGLUT_STATIC -I/usr/i586-mingw32msvc/include -lfreeglut_static -lopengl32 -lwinmm -lgdi32
#LIBSW=-I/usr/i586-mingw32msvc/include/SDL -L -lmingw32 -lSDLmain -lSDL -lwinmm -lgdi32 -mwindows -lm -lopengl32 -glu32 -Wl,-R
LIBSW=-I/usr/i586-mingw32msvc/include/SDL2 -static -L/usr/i586-mingw32msvc/bin -lmingw32 -lSDL2main -lSDL2  -mwindows  -lm -ldinput8 -ldxguid -ldxerr8 -luser32 -lgdi32 -lwinmm -limm32 -lole32 -loleaut32 -lshell32 -lversion -luuid -static-libgcc
#SOURCES=twink6.cpp
#SOURCES=test3_sdl2.cpp
#SOURCES=test1.cpp
SOURCES=main.cpp player.cpp innings.cpp team.cpp game.cpp screen.cpp

all: fielder_test bowler_test batsman_test player_test

LIBS_FIELDER_TEST=-L/usr/local/lib 
SOURCES_FIELDER_TEST=fielder_test.cpp fielder.cpp
OBJECTS_FIELDER_TEST=$(SOURCES_FIELDER_TEST:%.cpp=%.o)
fielder_test: $(OBJECTS_FIELDER_TEST)
	$(CC) $(LIBS_FIELDER_TEST) $^ -o $@ 

LIBS_BOWLER_TEST=-L/usr/local/lib 
SOURCES_BOWLER_TEST=bowler_test.cpp bowler.cpp
OBJECTS_BOWLER_TEST=$(SOURCES_BOWLER_TEST:%.cpp=%.o)
bowler_test: $(OBJECTS_BOWLER_TEST)
	$(CC) $(LIBS_BOWLER_TEST) $^ -o $@ 

LIBS_BATSMAN_TEST=-L/usr/local/lib 
SOURCES_BATSMAN_TEST=batsman_test.cpp batsman.cpp
OBJECTS_BATSMAN_TEST=$(SOURCES_BATSMAN_TEST:%.cpp=%.o)
batsman_test: $(OBJECTS_BATSMAN_TEST)
	$(CC) $(LIBS_BATSMAN_TEST) $^ -o $@ 

LIBS_PLAYER_TEST=-L/usr/local/lib 
SOURCES_PLAYER_TEST=player_test.cpp player.cpp batsman.cpp bowler.cpp fielder.cpp
OBJECTS_PLAYER_TEST=$(SOURCES_PLAYER_TEST:%.cpp=%.o)
player_test: $(OBJECTS_PLAYER_TEST)
	$(CC) $(LIBS_PLAYER_TEST) $^ -o $@ 

ma.exe: $(OBJECTSW)
	$(CCW) $^ -o $@ $(LIBSW)

ma: $(OBJECTS)
	$(CC) $(LIBS) $^ -o $@ 
	
clean:
	rm -rf *.o *.ow *.exe fielder_test bowler_test batsman_test player_test
