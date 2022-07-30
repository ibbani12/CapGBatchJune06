CC = g++
LFLAGS = -o
CFLAGS = -c -g 
INC = ./inc
IFLAG = -I$(INC)
BIN = ./bin
OBJ = ./obj
SRC = ./src

all: multiple1

multiple1: $(OBJ)/multiple1.o
	$(CC) $(LFLAGS) $(BIN)/multiple1 $(OBJ)/multiple1.o

$(OBJ)/multiple1.o:$(SRC)/multiple1.cpp
	$(CC) $(CFLAGS) $(IFLAG) $(SRC)/multiple1.cpp
	mv *.o $(OBJ)

clean:
	@echo "cleaning is in progress"
	rm -f a.out multiple1
	rm -f *.o
	rm -f $(OBJ)/*.o
	@echo "Done!"