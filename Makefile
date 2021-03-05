a.out:  matrix.o ganeLogic.o
	$(CC) -o game main.c matrix.o gameLogic.o

matrix.o: matrix.h
	$(CC) -c matrix.c

ganeLogic.o: gameLogic.h
	$(CC) -c gameLogic.c

.PHONY: clean

clean:
	-rm *.o
