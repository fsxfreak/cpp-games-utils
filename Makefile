CC=g++
CFLAGS=-c -Wall -Werror -std=c++11
INCLUDES=-I.
PROGNAME=isabel-game

.PHONY: clean

all: $(PROGNAME)
$(PROGNAME): main.o InputHandler.o Action.o Player.o
	$(CC) $(INCLUDES) main.o InputHandler.o Action.o Player.o -o $(PROGNAME)

main.o: main.cpp
	$(CC) $(CFLAGS) $(INCLUDES) main.cpp

InputHandler.o: InputHandler.cpp  
	$(CC) $(CFLAGS) $(INCLUDES) InputHandler.cpp

Action.o: Action.cpp
	$(CC) $(CFLAGS) $(INCLUDES) Action.cpp	

Player.o: Player.cpp
	$(CC) $(CFLAGS) $(INCLUDES) Player.cpp

clean:
	rm -rf *.o

