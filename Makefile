all: game
net_text.o: game.h game_io.h
	gcc -c net_text.c
game: game.o game_io.o net_text.o
	gcc -Wall -std=c99 game.o game_io.o net_text.o -o game
.phony: clean
clean:
	rm -f game net_text.o