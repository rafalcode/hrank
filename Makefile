CC=gcc
CFLAGS=-g -Wall
DBGCFLAGS=-g -Wall -DDBG
SPECLIBS=
BZLIBS=-lbz2

# looking for uov? chekc the juegoca repository

EXECUTABLES=cofarrmanip couinv

# HOw to fill a character array,
cofarrmanip: cofarrmanip.c
	${CC} ${CFLAGS} -o $@ $^

couinv: couinv.c
	${CC} ${CFLAGS} -o $@ $^

.PHONY: clean

clean:
	rm -f ${EXECUTABLES}
