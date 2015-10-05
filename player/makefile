all: src test build

.PHONY: src test build

src:
	gcc -c src/player.c -o ../build/player.o

test:
	$(MAKE) -C test all

build:
	$(MAKE) -C build all
