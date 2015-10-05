all: src test build

.PHONY: src test build

src:
	gcc -c src/gui_sdl.c -o ../build/gui_sdl.o

test:
	$(MAKE) -C test all

build:
	$(MAKE) -C build all
