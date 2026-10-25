CXX = g++
PYTHON = python

INCLUDES = -I./libraries/include
LIBS = -L./libraries/lib -l:libraylibdll.a -lgdi32 -lwinmm -lopengl32
POUTPUT = src/pendulum.exe
AOUTPUT = src/tests.exe

all:
	$(CXX) src/graphics.cpp $(INCLUDES) $(LIBS) -o $(POUTPUT)
run: all
	./$(POUTPUT)
datasets:
	$(CXX) src/tests.cpp -o $(AOUTPUT)
	./$(AOUTPUT)

test:
	$(PYTHON) src/analysis.py
