CXX = g++

INCLUDES = -I./libraries/include
LIBS = -L./libraries/lib -l:libraylibdll.a -lgdi32 -lwinmm -lopengl32
OUTPUT = src/pendulum.exe

all:
	$(CXX) src/graphics.cpp $(INCLUDES) $(LIBS) -o $(OUTPUT)
# run: all
# 	# ./$(OUTPUT)
