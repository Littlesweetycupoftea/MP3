all:
	mingw32-gcc.exe -Wall -g  -c "Player.c" -o Player.o
	mingw32-g++.exe  -o MP3.exe Player.o   -lwinmm
	
