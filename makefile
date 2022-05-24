CC = gcc
OUT = exec
FILES = genetica.c matriz.c main.c

target:
	${CC} -o ${OUT} ${FILES}
