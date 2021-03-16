
#
#
#
#

# vect.c --> vect.o      \______ liblinalg.a
# matrix.c --> matrix.o  /
# linalg.h <-- déclarer les fcts de vect.c et matrix.c
# linalg_types.h <-- déclarer types et macros

# test.c   \ _________ test.exe 
# liblinalg.a /

default: liblinalg.a test.exe

liblinalg.a : matrix.o vect.o
	ar -crs liblinalg.a matrix.o vect.o

matrix.o: matrix.c
	gcc -g -Wall -c matrix.c

vect.o: vect.c 
	gcc -g -Wall -c vect.c

test.o: test.c 
	gcc -g -Wall -c test.c

test.exe : test.o liblinalg.a
	gcc -L. test.o liblinalg.a -o test.exe

clean:
	rm -vf *.o *.exe *.a