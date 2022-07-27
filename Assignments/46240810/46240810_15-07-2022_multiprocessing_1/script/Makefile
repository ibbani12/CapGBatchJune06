CC = g++
CPPFLAGS = -c -Wall -Werror
OBJ = obj/
SRC = src/
BIN = bin/
INCLUDE = inc/

CVFLAGS = -v --tool=memcheck --leak-check=full --show-reachable=yes --log-file=valclient

all: app

app : $(OBJ)assign.o
	$(CC) -o app $(OBJ)assign.o
	mv app $(BIN)

$(OBJ)assign.o : $(SRC)assign.cpp
	$(CC) $(CPPFLAGS) $(SRC)assign.cpp -I $(INCLUDE)
	mv assign.o $(OBJ)

clean : 
	rm -f a.out app *.o
	rm -f $(OBJ)*.o
	rm -f $(BIN)app

valgrind:
	valgrind --leak-check=full $(BIN)/app
	mv valgrind $(BIN)
