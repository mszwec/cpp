APP= egzamin
SRC= *.cpp
OBJ= main.o

CFLAGS=-c -g -Wall

all: clean compile link

compile:
	g++ $(CFLAGS) $(SRC)

link:
	g++ $(OBJ) -o $(APP)

clean:
	rm -rf $(APP) $(OBJ) *o
