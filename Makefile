all: compile link

compile:
	g++ -Isrc/include -c game.cpp

link: 
	g++ game.o -o game -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system