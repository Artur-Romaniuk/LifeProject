a.out:  matrix.o gameLogic.o
	$(CC) -o game main.c matrix.o gameLogic.o -ggdb

matrix.o: matrix.h  matrix.c
	$(CC) -c matrix.c matrix.h -ggdb

ganeLogic.o: gameLogic.h gameLogic.c
	$(CC) -c gameLogic.c gameLogic.h -ggdb

.PHONY: clean

clean:
	-rm *.o *.gch
