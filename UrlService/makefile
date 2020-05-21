APP= a.out
SRC= main.cpp
OBJ= main.o

CFLAGS=-c -g -Wall

all: clean compile link

compile: $(SRC)
	$(CXX) $(CFLAGS) $(SRC)

link: compile
	$(CXX) $(OBJ) -o $(APP)

clean:
	rm -rf $(APP) $(OBJ) core
