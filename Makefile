LIB = -lsfml-graphics -lsfml-window -lsfml-system

all: game

main.o: main.cpp
	g++ -c "main.cpp" -o main.o

Game.o: Game.cpp
	g++ -c "Game.cpp" -o Game.o

Paddle.o: Paddle.cpp
	g++ -c "Paddle.cpp" -o Paddle.o

Ball.o: Ball.cpp
	g++ -c "Ball.cpp" -o Ball.o

Brick.o: Brick.cpp
	g++ -c "Brick.cpp" -o Brick.o

game: main.o Game.o Paddle.o Ball.o Brick.o
	@echo "BUILDING..."
	g++ -o game main.o Game.o Paddle.o Ball.o Brick.o $(LIB)

clean:
	@echo "Wiping out object files..."
	rm *.o game