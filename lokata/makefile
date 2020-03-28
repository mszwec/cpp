APP= lokata
SRC= *.c
OBJ= main.o
LIBOBJ= kapitalizacja.o
LIB=libkapitalizacja.a

CFLAGS=-c -g -Wall
LFLAGS=-L ./.

all: clean compile arch link

compile:
	g++ $(CFLAGS) $(SRC)

arch:
	ar rcs $(LIB) $(LIBOBJ)

link:
	g++ $(LFLAGS) $(OBJ) $(LIB) -o $(APP)

clean:
	rm -rf $(APP) $(LIBOBJ) $(LIB) $(OBJ)
