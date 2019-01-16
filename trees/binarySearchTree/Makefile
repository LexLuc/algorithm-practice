bstLab: bstLab.o bst.o queue.o
	gcc -Wall -Werror -std=c99 -o bstLab bstLab.o bst.o queue.o
bstLab.o: bstLab.c bst.h
	gcc -Wall -Werror -std=c99 -c bstLab.c
bst.o: bst.c bst.h ../../queue/queue.h
	gcc -Wall -Werror -std=c99 -c bst.c 
queue.o: ../../queue/queue.c ../../queue/queue.h
	gcc -Wall -Werror -std=c99 -c ../../queue/queue.c
clean:
	rm *.o bstLab