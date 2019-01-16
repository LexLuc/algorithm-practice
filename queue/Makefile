play: playQ.o queue.o
	gcc -Wall -Werror -o play playQ.o queue.o
playQ.o: playQ.c queue.h
	gcc -Wall -Werror -c playQ.c
queue.o: queue.c queue.h
	gcc -Wall -Werror -c queue.c