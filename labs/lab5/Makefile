CC=g++
CFLAGS=-c -g -Wall -Dmain=SDL_main
LDFLAGS=-lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -w -Wl,-subsystem,windows
SOURCES=model.cpp view.cpp controller.cpp main.cpp list.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=lab5.exe

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE):
	$(CC) -g $(SOURCES) $(LDFLAGS) -o $@

clean:
	rm $(EXECUTABLE)
