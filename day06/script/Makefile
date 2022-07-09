CC = g++
INC = ../inc
OBJ = ../obj
SRC = ../src
BIN = ../bin

CFLAGS = -c -g -Wall -Werror
LFLAGS = -o
IFLAGS = -I$(INC)

app: $(OBJ)/test.o
	$(CC) $(LFLAGS) $(BIN)/app $(OBJ)/test.o

$(OBJ)/test.o:$(SRC)/test.cpp
	$(CC) $(CFLAGS) $(IFLAGS) $(SRC)/test.cpp -o $(OBJ)/test.o 

