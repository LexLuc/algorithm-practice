binarySearch2D: binarySearch2D.o dynamic2DArray.o
	gcc -Wall -Werror -o binarySearch2D binarySearch2D.o dynamic2DArray.o

binarySearch2D.o: binarySearch2D.c dynamic2DArray.h
	gcc -Wall -Werror -c binarySearch2D.c

dynamic2DArray.o: dynamic2DArray.c dynamic2DArray.h
	gcc -Wall -Werror -c dynamic2DArray.c

clean:
	rm *.o binarySearch2D
