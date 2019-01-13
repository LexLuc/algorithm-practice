sortings: sortLab.o sortMain.c
	gcc -Wall -Werror -o sortings sortLab.o sortMain.c

sortLab.o: sortLab.c sortLab.h
	gcc -Wall -Werror -c sortLab.c sortLab.h

clean:
	rm *.o *gch sortings