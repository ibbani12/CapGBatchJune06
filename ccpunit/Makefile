CC = g++
CPPFLAGS = -c -Wall
LDFLAGS = -lcppunit -lm
OBJ = obj/
SRC = src/
BIN = bin/
INCLUDE = inc/

all: cpp

cpp: $(OBJ)TestDate.o $(OBJ)Date.o 
	$(CC) -o cpp $(OBJ)TestDate.o  $(OBJ)Date.o 
	mv cpp $(BIN) 

$(OBJ)TestDate.o: $(SRC)TestDate.cpp
	$(CC) $(CPPFLAGS) $(SRC)TestDate.cpp -I $(INCLUDE)
	mv TestDate.o $(OBJ)

$(OBJ)Date.o: $(SRC)Date.cpp
	$(CC) $(CPPFLAGS) $(SRC)Date.cpp -I $(INCLUDE)
	mv Date.o $(OBJ)


clean:
	rm -f a.out cpp *.o
	rm -f $(OBJ)*.o
	rm -f $(BIN)cpp