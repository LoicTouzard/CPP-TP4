EXE=tp4
INT=Circle.h Container.h Figure.h Graphics.h Line.h Polyline.h Rectangle.h Selection.h Command.h ComposedCommand.h CreateElementCommand.h DeleteCommand.h DeleteElementCommand.h LoadCommand.h MoveCommand.h SimpleCommand.h Tools.h

SRC=$(INT:.h=.cpp)
OBJ=$(INT:.h=.o)
	
MainSRC=main.cpp
MainOBJ=$(MainSRC:.cpp=.o)
	
ECHO=@echo

CLEAN=clean
RM=rm
RMFlags=-f

Compilator=@g++
CompilationsOptions=-Wall -pedantic -std=c++11
Linker=@g++
LinkerOptions=

all: $(EXE)

$(EXE): $(MainOBJ) $(OBJ)
	$(ECHO) "Edition des liens de $(EXE)"
	$(Linker) -o $(EXE) $(MainOBJ) $(OBJ) $(LinkerOptions)
	
$(MainOBJ): $(MainSRC) $(INT)
	$(ECHO) "Compilation de $(MainSRC)"
	$(Compilator) -o $(MainOBJ) -c $(MainSRC) $(CompilationsOptions)

%.o: %.cpp
	$(ECHO) "Compilation de $<"
	$(Compilator) -c $< $(CompilationsOptions)
	
# ***** CLEAN ***** #

.PHONY: $(CLEAN)
$(CLEAN):
	$(RM) $(RMFlags) $(EXE) $(OBJ) $(MainOBJ)