################################################################
# DAVID VARGAS CARRILLO
# github.com/dvcarrillo
# 
# MAKE FOR DemoDemoList.cpp
################################################################

BIN = bin
SRC = src
OBJ = obj
DOC = doc
LIB = lib
INCLUDE = include

#..........................................................
all:  preamble \
      clean\
      $(BIN)/DemoList

#..........................................................
preamble:
	@echo
	@echo -------------------------------------------------
	@echo DAVID VARGAS CARRILLO
	@echo github.com/dvcarrillo
	@echo
	@echo Program that creates, shows and releases from
	@echo memory a dynamic lineal list.
	@echo
	@echo Building the program, hold on...
	@echo -------------------------------------------------
	@echo

#....................................................................
# EJECUTABLES

$(BIN)/DemoList : $(OBJ)/DemoList.o $(OBJ)/List.o
	g++ -o $(BIN)/DemoList $(OBJ)/DemoList.o $(OBJ)/List.o

#..........................................................
# OBJECT FILES

$(OBJ)/List.o : $(SRC)/List.cpp $(INCLUDE)/List.h
	g++ -c -o $(OBJ)/List.o $(SRC)/List.cpp -I$(INCLUDE);

$(OBJ)/DemoList.o : $(SRC)/DemoList.cpp $(INCLUDE)/List.h
	g++ -c -o $(OBJ)/DemoList.o $(SRC)/DemoList.cpp -I$(INCLUDE);

#..........................................................
# CLEANING

clean: clean-objs clean-libs

clean-objs:
	@echo Cleaning object files...
	-rm $(OBJ)/DemoList.o
	-rm $(OBJ)/List.o
	@echo Cleaned.

clean-libs: 
	@echo Cleaning libraries...
	@echo Cleaned.

clean-bins:
	@echo Cleaning binary files...
	-rm $(BIN)/DemoList
	@echo Cleaned.

mr.proper: clean clean-bins
