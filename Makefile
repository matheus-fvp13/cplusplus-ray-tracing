APPS = ./apps
BIN = ./bin
INCLUDE = ./include
OBJ = ./obj
SRC = ./src

all: libgeo clean_apps myapps

libgeo: #\
	#$(OBJ)/float_vector.o \
	#$(OBJ)/mytime.o

myapps: \
	$(BIN)/main \
	#$(BIN)/app_com_mytime

$(OBJ)/%.o: $(SRC)/%.cpp $(INCLUDE)/%.h
	g++ -c $< -I $(INCLUDE) -o $@

$(BIN)/%: $(APPS)/%.cpp
	g++ $< -I $(INCLUDE) -o $@

run:
	$(BIN)/main

clean:
	rm -rf $(BIN)/* $(OBJ)/*

clean_apps:
	rm -rf $(BIN)/*