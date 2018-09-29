CFLAGS = -g -Wall -std=c99
CPPFLAGS = -I .
LDFLAGS = -L . -lgame
OBJETS = net_text.o game.o game_io.o


net_text: libgame.a
	$(CC) -o $@ $^

net_text.o: net_text.c game.h game_io.h

libgame.a: $(OBJETS)
	ar -r $@ $^

.phony: clean
clean:
	rm -f net_text net_text.o libgame.a