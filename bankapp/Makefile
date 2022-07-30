CC = g++
CPPFLAGS = -c -Wall
LDFLAGS = -lcppunit -lm
OBJ = obj/
SRC = src/
BIN = bin/
INCLUDE = inc/

all: app

app: $(OBJ)child.o $(OBJ)main.o
	$(CC) -o app $(OBJ)child.o $(OBJ)main.o
	mv app $(BIN) 

$(OBJ)main.o: $(SRC)main.cpp
	$(CC) $(CPPFLAGS) $(SRC)main.cpp -I $(INCLUDE)
	mv main.o $(OBJ)

$(OBJ)child.o: $(SRC)child.cpp
	$(CC) $(CPPFLAGS) $(SRC)child.cpp -I $(INCLUDE)
	mv child.o $(OBJ)




clean:
	rm -f a.out app *.o
	rm -f $(OBJ)*.o
	rm -f $(BIN)app