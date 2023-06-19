all: compile link

compile:
	g++ -Isrc/include -c MainMenu.cpp MENUSFML.cpp 

link: 
	g++ MainMenu.o MENUSFML.o -o level1 -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system