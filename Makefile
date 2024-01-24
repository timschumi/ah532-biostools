.PHONY: all
all: fixboot

fixboot: fixboot.c
	gcc -o $@ $< -lefivar
