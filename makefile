
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

default: liblinalg.a test.exe test_matrix.exe multiD-example.exe

liblinalg.a : matrix.o vect.o
	ar -crs liblinalg.a matrix.o vect.o

matrix.o: matrix.c
	gcc -g -Wall -c matrix.c

vect.o: vect.c 
	gcc -g -Wall -c vect.c

test.o: test.c 
	gcc -g -Wall -c test.c

test_matrix.o: test_matrix.c 
	gcc -g -Wall -c test_matrix.c

test.exe : test.o liblinalg.a
	gcc -L. test.o liblinalg.a -o test.exe

test_matrix.exe : test_matrix.o liblinalg.a
	gcc -L. test_matrix.o liblinalg.a -o test_matrix.exe

multiD-example.o : multiD-example.c
	gcc -c multiD-example.c

multiD-example.exe : multiD-example.o
	gcc -o multiD-example.exe multiD-example.o

clean:
	rm -vf *.o *.exe *.a