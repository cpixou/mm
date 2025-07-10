CC = gcc
CFLAGS = -O3 -Wall -Wextra -std=c99
LDFLAGS = -lgmp

SRC = mm.c
BIN = mm
PREFIX = /usr/bin

all: $(BIN)

$(BIN): $(SRC)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)

install: $(BIN)
	install -m 755 $(BIN) $(PREFIX)

uninstall:
	rm -f $(PREFIX)/$(BIN)

clean:
	rm -f $(BIN)
