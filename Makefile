CC=g++
CCW=i586-mingw32msvc-g++

OBJECTS=$(SOURCES:%.cpp=%.o)
OBJECTSW=$(SOURCES:%.cpp=%.ow)

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@	
	
%.ow: %.cpp	
	$(CCW) $(CFLAGSW) $< -o $@

CFLAGS=-std=c++0x -Wall -I/usr/include/ -c


#CFLAGS=-Wall -c
#CFLAGS=-Wall -Dmain=SDL_main -c
#CFLAGSW=-D FREEGLUT_STATIC -I/usr/i586-mingw32msvc/include/ -Wall -c
CFLAGSW=-I/usr/i586-mingw32msvc/SDL2-2.0.3/include/ -c
CFLAGSWA=-L/usr/i586-mingw32msvc/lib/ -I/usr/i586-mingw32msvc/SDL2-2.0.3/include/
#CFLAGSW=-I/usr/i586-mingw32msvc/include/SDL2 -Dmain=SDL_main -Wall -c
#LIBS=-lGL -lglut
LIBS=-lSDL2 -lGL -lSDL2_image -lSDL2_ttf
LIBSW=-lmingw32 -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image -mwindows -lm -ldinput8 -ldxguid -ldxerr8 -luser32 -lgdi32 -lwinmm -limm32 -lole32 -loleaut32 -lshell32 -lversion -luuid -static-libgcc 
#LIBSW=-D FREEGLUT_STATIC -mwindows  -lwinmm -static -static-libgcc -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -mwindows -lm -ldinput8 -ldxguid -ldxerr8 -luser32 -lgdi32 -lwinmm -limm32 -lole32 -loleaut32 -lshell32 -lversion -luuid -static-libgcc  
#LIBSW=-D FREEGLUT_STATIC -I/usr/i586-mingw32msvc/include -lfreeglut_static -lopengl32 -lwinmm -lgdi32
#LIBSW=-I/usr/i586-mingw32msvc/include/SDL -L -lmingw32 -lSDLmain -lSDL -lwinmm -lgdi32 -mwindows -lm -lopengl32 -glu32 -Wl,-R
#LIBSW=-I/usr/i586-mingw32msvc/include/SDL2 -static -L/usr/i586-mingw32msvc/bin -lmingw32 -lSDL2main -lSDL2  -mwindows  -lm -ldinput8 -ldxguid -ldxerr8 -luser32 -lgdi32 -lwinmm -limm32 -lole32 -loleaut32 -lshell32 -lversion -luuid -static-libgcc
#SOURCES=twink6.cpp
#SOURCES=test3_sdl2.cpp
#SOURCES=test1.cpp
#SOURCES=main.cpp player.cpp innings.cpp team.cpp game.cpp screen.cpp
SOURCES=main.cpp game.cpp screen.cpp

all: ma ma.exe fielder_test bowler_test batsman_test player_test innings_test

# linux_programs windows_programs

linux_programs: fielder_test bowler_test batsman_test player_test innings_test
windows_programs: fielder_test.exe bowler_test.exe batsman_test.exe player_test.exe
# innings_test.exe

LIBS_FIELDER_TEST=-L/usr/local/lib 
SOURCES_FIELDER_TEST=fielder_test.cpp fielder.cpp
OBJECTS_FIELDER_TEST=$(SOURCES_FIELDER_TEST:%.cpp=%.o)
fielder_test: $(OBJECTS_FIELDER_TEST)
	$(CC) $(LIBS_FIELDER_TEST) $^ -o $@ 

LIBSW_FIELDER_TEST=-L/usr/local/lib -mwindows 
SOURCES_FIELDER_TEST=fielder_test.cpp fielder.cpp
OBJECTSW_FIELDER_TEST=$(SOURCES_FIELDER_TEST:%.cpp=%.ow)
fielder_test.exe: $(OBJECTSW_FIELDER_TEST)
	$(CCW) $(LIBSW_FIELDER_TEST) $^ -o $@ 

LIBS_BOWLER_TEST=-L/usr/local/lib 
SOURCES_BOWLER_TEST=bowler_test.cpp bowler.cpp
OBJECTS_BOWLER_TEST=$(SOURCES_BOWLER_TEST:%.cpp=%.o)
bowler_test: $(OBJECTS_BOWLER_TEST)
	$(CC) $(LIBS_BOWLER_TEST) $^ -o $@ 

LIBSW_BOWLER_TEST=-L/usr/local/lib -mwindows 
SOURCES_BOWLER_TEST=bowler_test.cpp bowler.cpp
OBJECTSW_BOWLER_TEST=$(SOURCES_BOWLER_TEST:%.cpp=%.ow)
bowler_test.exe: $(OBJECTSW_BOWLER_TEST)
	$(CCW) $(LIBSW_BOWLER_TEST) $^ -o $@ 

LIBS_BATSMAN_TEST=-L/usr/local/lib 
SOURCES_BATSMAN_TEST=batsman_test.cpp batsman.cpp
OBJECTS_BATSMAN_TEST=$(SOURCES_BATSMAN_TEST:%.cpp=%.o)
batsman_test: $(OBJECTS_BATSMAN_TEST)
	$(CC) $(LIBS_BATSMAN_TEST) $^ -o $@ 

LIBSW_BATSMAN_TEST=-L/usr/local/lib -mwindows 
SOURCES_BATSMAN_TEST=batsman_test.cpp batsman.cpp
OBJECTSW_BATSMAN_TEST=$(SOURCES_BATSMAN_TEST:%.cpp=%.ow)
batsman_test.exe: $(OBJECTSW_BATSMAN_TEST)
	$(CCW) $(LIBSW_BATSMAN_TEST) $^ -o $@ 

LIBS_PLAYER_TEST=-L/usr/local/lib 
SOURCES_PLAYER_TEST=player_test.cpp player.cpp batsman.cpp bowler.cpp fielder.cpp
OBJECTS_PLAYER_TEST=$(SOURCES_PLAYER_TEST:%.cpp=%.o)
player_test: $(OBJECTS_PLAYER_TEST)
	$(CC) $(LIBS_PLAYER_TEST) $^ -o $@ 

LIBSW_PLAYER_TEST=-L/usr/local/lib -mwindows 
SOURCES_PLAYER_TEST=player_test.cpp player.cpp batsman.cpp bowler.cpp fielder.cpp
OBJECTSW_PLAYER_TEST=$(SOURCES_PLAYER_TEST:%.cpp=%.ow)
player_test.exe: $(OBJECTSW_PLAYER_TEST)
	$(CCW) $(LIBSW_PLAYER_TEST) $^ -o $@ 

LIBS_INNINGS_TEST=-L/usr/local/lib 
SOURCES_INNINGS_TEST=innings_test.cpp player.cpp batsman.cpp bowler.cpp fielder.cpp innings.cpp
OBJECTS_INNINGS_TEST=$(SOURCES_INNINGS_TEST:%.cpp=%.o)
innings_test: $(OBJECTS_INNINGS_TEST)
	$(CC) $(LIBS_INNINGS_TEST) $^ -o $@ 

ma.exe: $(OBJECTSW)
	$(CCW) $(CFLAGSWA) $^ $(LIBSW) -o $@ 

ma: $(OBJECTS)
	$(CC) $^ $(LIBS) -o $@ 
	
clean:
	rm -rf *.o *.ow *.exe fielder_test bowler_test batsman_test player_test innings_test ma
