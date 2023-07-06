all:compile link

compile:
	g++ -c win.cpp WinMain.cpp -Isrc/include
link:
	g++ win.o WinMain.o -o win -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio