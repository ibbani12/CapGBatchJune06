CC = g++
CPPFLAGS = -c -Wall
LDFLAGS = -lcppunit -lm
OBJ = obj/
SRC = src/
BIN = bin/
INCLUDE = inc/

all: app

app: $(OBJ)Main.o $(OBJ)Vechicle.o $(OBJ)FourWheeler.o
	$(CC) -o app $(OBJ)Main.o  $(OBJ)Vechicle.o $(OBJ)FourWheeler.o
	mv app $(BIN) 

$(OBJ)Main.o: $(SRC)Main.cpp
	$(CC) $(CPPFLAGS) $(SRC)Main.cpp -I $(INCLUDE)
	mv Main.o $(OBJ)

$(OBJ)Vechicle.o: $(SRC)Vechicle.cpp
	$(CC) $(CPPFLAGS) $(SRC)Vechicle.cpp -I $(INCLUDE)
	mv Vechicle.o $(OBJ)

$(OBJ)FourWheeler.o: $(SRC)FourWheeler.cpp
	$(CC) $(CPPFLAGS) $(SRC)FourWheeler.cpp -I $(INCLUDE)
	mv FourWheeler.o $(OBJ)


clean:
	rm -f a.out app *.o
	rm -f $(OBJ)*.o
	rm -f $(BIN)app

