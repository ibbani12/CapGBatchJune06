CC = g++
LFLAGS = -o
CFLAGS = -c -g 
INC = ./inc
IFLAG = -I$(INC)
BIN = ./bin
OBJ = ./obj
SRC = ./src

all: sysPrg1 sysPrg2 sysPrg3 sysPrg4 sysPrg5 sysPrg6

sysPrg1: $(OBJ)/sysPrg1.o
	$(CC) $(LFLAGS) $(BIN)/sysPrg1 $(OBJ)/sysPrg1.o

$(OBJ)/sysPrg1.o: $(SRC)/sysPrg1.cpp
	$(CC) $(CFLAGS) $(IFLAG) $(SRC)/sysPrg1.cpp 
	mv *.o $(OBJ)

sysPrg2: $(OBJ)/sysPrg2.o
	$(CC) $(LFLAGS) $(BIN)/sysPrg2 $(OBJ)/sysPrg2.o

$(OBJ)/sysPrg2.o: $(SRC)/sysPrg2.cpp
	$(CC) $(CFLAGS) $(IFLAG) $(SRC)/sysPrg2.cpp 
	mv *.o $(OBJ)

sysPrg3: $(OBJ)/sysPrg3.o
	$(CC) $(LFLAGS) $(BIN)/sysPrg3 $(OBJ)/sysPrg3.o

$(OBJ)/sysPrg3.o: $(SRC)/sysPrg3.cpp
	$(CC) $(CFLAGS) $(IFLAG) $(SRC)/sysPrg3.cpp 
	mv *.o $(OBJ)

sysPrg4: $(OBJ)/sysPrg4.o
	$(CC) $(LFLAGS) $(BIN)/sysPrg4 $(OBJ)/sysPrg4.o

$(OBJ)/sysPrg4.o: $(SRC)/sysPrg4.cpp
	$(CC) $(CFLAGS) $(IFLAG) $(SRC)/sysPrg4.cpp 
	mv *.o $(OBJ)

sysPrg5: $(OBJ)/sysPrg5.o
	$(CC) $(LFLAGS) $(BIN)/sysPrg5 $(OBJ)/sysPrg5.o

$(OBJ)/sysPrg5.o: $(SRC)/sysPrg5.cpp
	$(CC) $(CFLAGS) $(IFLAG) $(SRC)/sysPrg5.cpp 
	mv *.o $(OBJ)

sysPrg6: $(OBJ)/sysPrg6.o
	$(CC) $(LFLAGS) $(BIN)/sysPrg6 $(OBJ)/sysPrg6.o

$(OBJ)/sysPrg6.o: $(SRC)/sysPrg6.cpp
	$(CC) $(CFLAGS) $(IFLAG) $(SRC)/sysPrg6.cpp 
	mv *.o $(OBJ)

clean:
	@echo "Cleaning is in Progress"
	rm -f a.out sysPrg1
	rm -f *.o
	rm -f $(OBJ)/*.o
	rm -f $(BIN)/sysPrg1 $(BIN)/sysPrg2 $(BIN)/sysPrg3
	rm -f $(BIN)/sysPrg4 $(BIN)/sysPrg5
	rm -f $(BIN)/*
	@echo "Done!"


