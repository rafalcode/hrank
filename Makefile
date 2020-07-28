CC=gcc
CFLAGS=-g -Wall
DBGCFLAGS=-g -Wall -DDBG

# looking for uov? chekc the juegoca repository

EXECUTABLES=cofarrmanip couinv0 couinv

# HOw to fill a character array,
cofarrmanip: cofarrmanip.c
	${CC} ${CFLAGS} -o $@ $^

# this is prep for courinv ... only focuses on getting input right.
couinv0: couinv0.c
	${CC} ${CFLAGS} -o $@ $^

couinv: couinv.c
	${CC} ${CFLAGS} -o $@ $^

.PHONY: clean

clean:
	rm -f ${EXECUTABLES}
