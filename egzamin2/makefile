APP= egzamin
SRC= *.c
OBJ= kapitalizacja.o main.o

CFLAGS=-c -g -Wall

all: clean compile link

compile:
	g++ $(CFLAGS) $(SRC)

link:
	g++ $(OBJ) -o $(APP)

clean:
	rm -rf $(APP) $(OBJ)
