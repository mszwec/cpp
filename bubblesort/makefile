APP= sort
SRC= main.c
OBJ= main.o
CC=g++

CFLAGS=-c -g -Wall

.PHONY=clean compile link
all: clean compile link

compile: *.h
	$(CC) $(CFLAGS) $(SRC) -o $(OBJ)

link:
	$(CC) $(OBJ) -o $(APP)

clean:
	rm -rf $(APP) $(OBJ)
