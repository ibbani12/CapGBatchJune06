LDFLAGS = -lcppunit -lm
OBJ = obj/
SRC = src/
BIN = bin/
INCLUDE = inc/

all: app

app: $(OBJ)main.o $(OBJ)Employee.o
	$(CC) $(LFLAGS) $(BIN)app  $(OBJ)/main.o $(OBJ)Employee.o

$(OBJ)/main.o: $(SRC)main.cpp
	$(CC) $(CPPFLAGS) $(IFLAG) $(SRC)/main.cpp
	mv main.o $(OBJ)




clean:
	rm -f a.out app *.o
	rm -f $(OBJ)*.o
	rm -f $(BIN)app