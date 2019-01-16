#include <stdio.h>
#include "queue.h"

int main(void) {
	queue Q = newQueue();
	printf("\nis empty? %s\n", queueIsEmpty(Q)?"True":"False");
	showQueue(Q);
	
	printf("\nEnqueuing:\n");
	int i;
	for (i = 0; i < 10; i++) {
		enqueue(Q, i);
		showQueue(Q);
	}
	
	printf("\nis empty? %s\n", queueIsEmpty(Q)?"True":"False");
	
	printf("\nDequeuing:\n");\
	for (i = 0; i < 10; i++) {
		int data = dequeue(Q);
		printf("\nelement dequeued: %d", data);
		showQueue(Q);
	}
	
	dropQueue(Q);
	
	return 0;
}