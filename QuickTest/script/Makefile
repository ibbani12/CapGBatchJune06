CC = g++;
CPPFLAGS = -c - Wall - Werror
LFLAGS = -o
BIN = bin
OBJ = obj
SRC = src
INC =inc

all:app

app: $(OBJ)fork.o 
	$(CC) $(LFLAGS) $(BIN)fork.o $(OBJ)fork.o

$(OBJ)fork.o: $(SRC)fork.cpp	
	 $(CC) $(CPPFLAGS) $(IFLAGS) $(SRC)fork.cpp
	 mv *.o $(OBJ)
	

clean:
	rm -f a.out fork *.o
	rm -f $(OBJ)*.o
	rm -f $(BIN)app