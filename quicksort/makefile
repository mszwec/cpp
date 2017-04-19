APP= sort
SRC= main.c
OBJ= main.o
CC=g++

CFLAGS=-c -g -Wall

all: clean compile link

compile:
	$(CC) $(CFLAGS) $(SRC)

link:
	$(CC) $(OBJ) -o $(APP)

clean:
	rm -rf $(APP) $(OBJ) core
