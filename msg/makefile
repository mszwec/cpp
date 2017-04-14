OUT= app
CFLAGS= -Wall -g 
CC= g++
SRC= *cpp


all: clean
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

clean:
	rm -rf *o $(OUT)

flag: CFLAGS += -DMSZ
flag: clean all
