all: src test build

.PHONY: src test build

src:
	gcc -c src/stats.c -o ../build/stats.o

test:
	$(MAKE) -C test all

build:
	$(MAKE) -C build all
