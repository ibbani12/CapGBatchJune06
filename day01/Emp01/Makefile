CC = g++
CPPFLAGS = -c -Wall
LDFLAGS = -lcppunit -lm
OBJ = obj/
SRC = src/
BIN = bin/
INCLUDE = inc/

all: app

app: $(OBJ)Main.o $(OBJ)Employee.o $(OBJ)Person.o
	$(CC) -o app $(OBJ)Main.o  $(OBJ)Employee.o $(OBJ)Person.o
	mv app $(BIN) 

$(OBJ)Main.o: $(SRC)Main.cpp
	$(CC) $(CPPFLAGS) $(SRC)Main.cpp -I $(INCLUDE)
	mv Main.o $(OBJ)

$(OBJ)Employee.o: $(SRC)Employee.cpp
	$(CC) $(CPPFLAGS) $(SRC)Employee.cpp -I $(INCLUDE)
	mv Employee.o $(OBJ)

$(OBJ)Person.o: $(SRC)Person.cpp
	$(CC) $(CPPFLAGS) $(SRC)Person.cpp -I $(INCLUDE)
	mv Person.o $(OBJ)


clean:
	rm -f a.out app *.o
	rm -f $(OBJ)*.o
	rm -f $(BIN)app

