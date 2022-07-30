CC = g++
CPPFLAGS = -c -Wall -Werror -std=c++11
LFLAGS = -o

BIN = bin
OBJ = obj
SRC = src
INC = inc
DATA = data

app: $(OBJ)/Main.o $(OBJ)/Student.o $(OBJ)/config.o 
	$(CC) $(LFLAGS) $(BIN)/app $(OBJ)/Main.o $(OBJ)/config.o $(OBJ)/Student.o

$(OBJ)/config.o: $(SRC)/config.cpp
	$(CC) $(CPPFLAGS) -I$(INC) $(SRC)/config.cpp
	mv *.o $(OBJ)/

$(OBJ)/Main.o: $(SRC)/Main.cpp
	$(CC) $(CPPFLAGS) -I$(INC) $(SRC)/Main.cpp
	mv *.o $(OBJ)/

$(OBJ)/Student.o: $(SRC)/Student.cpp
	$(CC) $(CPPFLAGS) -I$(INC) $(SRC)/Student.cpp
	mv *.o $(OBJ)/

clean:
	rm -f a.out app
	rm -f $(OBJ)/*.o $(BIN)/app
	@echo "Cleaning Done!"