APPS = ./apps
BIN = ./bin
INCLUDE = ./include
OBJ = ./obj
SRC = ./src

all: libgeo clean_apps myapps

libgeo: \
	$(OBJ)/image_manager.o \
	#$(OBJ)/mytime.o

myapps: \
	$(BIN)/main \
	#$(BIN)/app_com_mytime

$(OBJ)/%.o: $(SRC)/%.cpp $(INCLUDE)/%.h
	g++ -c $< -I $(INCLUDE) -o $@ 

$(BIN)/%: $(APPS)/%.cpp
	g++ `Magick++-config --cxxflags --cppflags` $< -I $(INCLUDE) $(OBJ)/*.o -o $@ `Magick++-config --ldflags --libs`

run:
	$(BIN)/main

clean:
	rm -rf $(BIN)/* $(OBJ)/*

clean_apps:
	rm -rf $(BIN)/*