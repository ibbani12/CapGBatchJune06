CC = g++
INC = ./inc
OBJ = ./obj
SRC = ./src
BIN = ./bin

CFLAGS = -c -g -Wall -Werror
LFLAGS = -o
IFLAGS = -I$(INC)
CVFLAGS = -v --tool=memcheck --leak-check=full --show-reachable=yes --log-file=valclient

all: $(BIN)/app $(BIN)/app2 valgrind

$(BIN)/app: $(OBJ)/test.o
	$(CC) $(LFLAGS) $(BIN)/app $(OBJ)/test.o

$(BIN)/app2: $(OBJ)/test1.o
	$(CC) $(LFLAGS) $(BIN)/app2 $(OBJ)/test1.o


$(OBJ)/test.o:$(SRC)/test.cpp
	$(CC) $(CFLAGS) $(IFLAGS) $(SRC)/test.cpp -o $(OBJ)/test.o 

$(OBJ)/test1.o:$(SRC)/test1.cpp
	$(CC) $(CFLAGS) $(IFLAGS) $(SRC)/test1.cpp -o $(OBJ)/test1.o 


clean:
	@echo "Cleaning the Project"
	rm -f $(OBJ)/*.o
	rm -f a.out
	rm -f $(BIN)/app
	rm -f $(BIN)/app2

valgrind:
	valgrind --leak-check=full $(BIN)/app
	mv valgrind $(BIN)
