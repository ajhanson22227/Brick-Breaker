LIB = -lsfml-graphics -lsfml-window -lsfml-system

all: test

main.o: main.cpp
	g++ -c "main.cpp" -o main.o

Game.o: Game.cpp
	g++ -c "Game.cpp" -o Game.o

test: main.o Game.o
	@echo "BUILDING..."
	g++ -o test main.o Game.o $(LIB)

clean:
	@echo "Wiping out object files..."
	rm *.o test