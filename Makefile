CC = g++
CFLAGS = -std=c++14 -c -g -Og -Wall -Werror -pedantic 
OBJ = CircularBuffer.o StringSound.o KSGuitarSim.o
DEPS = 
LIBS = -lsfml-system -lsfml-audio -lsfml-graphics -lsfml-window
EXE = KSGuitarSim

all: $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm $(OBJ) $(EXE)
