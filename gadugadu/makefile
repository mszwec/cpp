CAPP= client
SAPP= server
APP= $(CAPP) $(SAPP)
SRC= main.c
SOBJ= server.o
COBJ= client.o
OBJ= $(COBJ) $(SOBJ)
CC=gcc

CFLAGS=-c -g -Wall

all: clean compile link

compile: $(OBJ)

$(COBJ):
	$(CC) $(CFLAGS) -DCLIENT $(SRC) -o $(COBJ)


$(SOBJ):
	$(CC) $(CFLAGS) -DSERVER $(SRC) -o $(SOBJ)

link: $(APP)

$(CAPP):
	$(CC) $(COBJ) -o $(CAPP)


$(SAPP):
	$(CC) $(SOBJ) -o $(SAPP)

clean:
	rm -rf $(APP) $(OBJ)
