all: game_logic gui player stats main build

.PHONY: game_logic gui player stats main build

game_logic:
	$(MAKE) -C game_logic all

gui:
	$(MAKE) -C gui all

player:
	$(MAKE) -C player all

stats:
	$(MAKE) -C stats all

main:
	$(MAKE) -C main all

build:
	$(MAKE) -C build all
