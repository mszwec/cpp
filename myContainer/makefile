APP= cpp
SRC= *.c
OBJ= main.o

CFLAGS=-c -g -Wall -std=c++17 -o $(OBJ)

all: clean compile link

compile:
	g++ $(CFLAGS) $(SRC)

link:
	g++ $(OBJ) -o $(APP)

clean:
	rm -rf $(APP) $(OBJ)
