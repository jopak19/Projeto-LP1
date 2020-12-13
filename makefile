
BIN = ./bin
SRC = ./src
INC = ./include
LIB_DIR = ./lib

PROG = programa
CC = g++
CPPFLAGS = -Wall -std=c++11 -I./include

OBJS = $(BIN)/main.o $(BIN)/petfera.o $(BIN)/animal.o $(BIN)/ave.o $(BIN)/anfibio.o $(BIN)/mamifero.o $(BIN)/reptil.o $(BIN)/funcionario.o $(BIN)/tratador.o $(BIN)/veterinario.o $(BIN)/interface.o $(BIN)/nativo.o $(BIN)/exotico.o $(BIN)/silvestre.o $(BIN)/anfibioexotico.o $(BIN)/anfibionativo.o $(BIN)/aveexotico.o $(BIN)/avenativo.o $(BIN)/mamiferoexotico.o $(BIN)/mamiferonativo.o $(BIN)/reptilexotico.o $(BIN)/reptilnativo.o $(BIN)/io.o

all :
	$(CC) $(CPPFLAGS) $(SRC)/main.cpp $(SRC)/petfera.cpp $(SRC)/interface.cpp $(LIB_DIR)/petshop.so -o $(PROG)

debug: CPPFLAGS += -DDEBUG -g -O0
debug: clean all

petshop.so: $(SRC)/anfibio.cpp $(SRC)/anfibioexotico.cpp $(SRC)/anfibionativo.cpp $(SRC)/animal.cpp $(SRC)/ave.cpp $(SRC)/aveexotico.cpp $(SRC)/avenativo.cpp $(SRC)/exotico.cpp $(SRC)/funcionario.cpp $(SRC)/mamifero.cpp $(SRC)/mamiferoexotico.cpp $(SRC)/mamiferonativo.cpp $(SRC)/nativo.cpp $(SRC)/reptil.cpp $(SRC)/reptilexotico.cpp $(SRC)/reptilnativo.cpp $(SRC)/silvestre.cpp $(SRC)/tratador.cpp $(SRC)/veterinario.cpp $(SRC)/io.cpp $(INC)/anfibio.hpp $(INC)/anfibioexotico.hpp $(INC)/anfibionativo.hpp $(INC)/animal.hpp $(INC)/ave.hpp $(INC)/aveexotico.hpp $(INC)/avenativo.hpp $(INC)/exotico.hpp $(INC)/funcionario.hpp $(INC)/mamifero.hpp $(INC)/mamiferoexotico.hpp $(INC)/mamiferonativo.hpp $(INC)/nativo.hpp $(INC)/reptil.hpp $(INC)/reptilexotico.hpp $(INC)/reptilnativo.hpp $(INC)/silvestre.hpp $(INC)/tratador.hpp $(INC)/veterinario.hpp $(INC)/io.hpp
	$(CC) $(CPPFLAGS) -fPIC -c $(SRC)/animal.cpp -o $(BIN)/animal.o
	$(CC) $(CPPFLAGS) -fPIC -c $(SRC)/ave.cpp -o $(BIN)/ave.o
	$(CC) $(CPPFLAGS) -fPIC -c $(SRC)/anfibio.cpp -o $(BIN)/anfibio.o
	$(CC) $(CPPFLAGS) -fPIC -c $(SRC)/mamifero.cpp -o $(BIN)/mamifero.o
	$(CC) $(CPPFLAGS) -fPIC -c $(SRC)/reptil.cpp -o $(BIN)/reptil.o
	$(CC) $(CPPFLAGS) -fPIC -c $(SRC)/funcionario.cpp -o $(BIN)/funcionario.o
	$(CC) $(CPPFLAGS) -fPIC -c $(SRC)/tratador.cpp -o $(BIN)/tratador.o
	$(CC) $(CPPFLAGS) -fPIC -c $(SRC)/veterinario.cpp -o $(BIN)/veterinario.o
	$(CC) $(CPPFLAGS) -fPIC -c $(SRC)/nativo.cpp -o $(BIN)/nativo.o
	$(CC) $(CPPFLAGS) -fPIC -c $(SRC)/exotico.cpp -o $(BIN)/exotico.o
	$(CC) $(CPPFLAGS) -fPIC -c $(SRC)/silvestre.cpp -o $(BIN)/silvestre.o
	$(CC) $(CPPFLAGS) -fPIC -c $(SRC)/anfibioexotico.cpp -o $(BIN)/anfibioexotico.o
	$(CC) $(CPPFLAGS) -fPIC -c $(SRC)/anfibionativo.cpp -o $(BIN)/anfibionativo.o 
	$(CC) $(CPPFLAGS) -fPIC -c $(SRC)/aveexotico.cpp -o $(BIN)/aveexotico.o 
	$(CC) $(CPPFLAGS) -fPIC -c $(SRC)/avenativo.cpp -o $(BIN)/avenativo.o
	$(CC) $(CPPFLAGS) -fPIC -c $(SRC)/mamiferoexotico.cpp -o $(BIN)/mamiferoexotico.o 
	$(CC) $(CPPFLAGS) -fPIC -c $(SRC)/mamiferonativo.cpp -o $(BIN)/mamiferonativo.o
	$(CC) $(CPPFLAGS) -fPIC -c $(SRC)/reptilexotico.cpp -o $(BIN)/reptilexotico.o
	$(CC) $(CPPFLAGS) -fPIC -c $(SRC)/reptilnativo.cpp -o $(BIN)/reptilnativo.o
	$(CC) $(CPPFLAGS) -fPIC -c $(SRC)/io.cpp -o $(BIN)/io.o
	$(CC) -shared -fPIC -o $(LIB_DIR)/$@ $(BIN)/anfibio.o $(BIN)/anfibioexotico.o $(BIN)/anfibionativo.o $(BIN)/animal.o $(BIN)/ave.o $(BIN)/aveexotico.o $(BIN)/avenativo.o $(BIN)/exotico.o $(BIN)/funcionario.o $(BIN)/mamifero.o $(BIN)/mamiferoexotico.o $(BIN)/mamiferonativo.o $(BIN)/nativo.o $(BIN)/reptil.o $(BIN)/reptilexotico.o $(BIN)/reptilnativo.o $(BIN)/silvestre.o $(BIN)/tratador.o $(BIN)/veterinario.o $(BIN)/io.o
	@echo "biblioteca criada ..."
 
clean:
	rm -f core $(PROG) $(OBJS)
