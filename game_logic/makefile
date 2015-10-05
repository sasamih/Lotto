all: src test build

.PHONY: src test build

src:
	gcc -c src/logic.c -o ../build/logic.o

test:
	$(MAKE) -C test all

build:
	$(MAKE) -C build all
