a.out:  matrix.o
	$(CC) -o game main.c matrix.o

matrix.o: matrix.h
	$(CC) -c matrix.c matrix.h

.PHONY: clean

clean:
	-rm *.o
