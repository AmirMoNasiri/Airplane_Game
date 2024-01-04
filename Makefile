all: compile link 

compile:
	g++ -c src/main.cpp src/AirplaneGame.cpp src/menu.cpp src/game.cpp

link:
	g++ main.o AirplaneGame.o menu.o game.o app.o -o app