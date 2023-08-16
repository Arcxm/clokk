CC=gcc
CCFLAGS=-Wall -Wextra

.PHONY: all

all: clokk

clokk: clokk.c
	${CC} ${CCFLAGS} -o clokk clokk.c