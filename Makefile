all: compile link

compile:
	g++ -Isrc/include -c game.cpp Hero.cpp Enemy.cpp

link: 
	g++ game.o Hero.o Enemy.o -o game -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system 
	