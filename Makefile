FILES = solarsystem.cpp planet.cpp lutil.cpp main.cpp

COMPILER = g++

COMPILER_FLAGS = -w -I/usr/include/freetype2

LINKER_FLAGS = -lGL -lGLU -lglut

EXEC = spacesim

all : $(FILES)
	$(COMPILER) $(FILES) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(EXEC)
