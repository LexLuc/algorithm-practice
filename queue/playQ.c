#include <stdio.h>
#include "queue.h"

#define LENGTH 10

/**
 * Unpack the node value pointer to the real value:
 * Node value is the pointer of integer in this case
 */
void unpackValue(void *value) {
	printf("-%d-", *(int *)value);
}

int main(void) {
	Queue Q = newQueue();
	printf("\nis empty? %s\n", queueIsEmpty(Q) ? "True" : "False");
	showQueue(Q, &unpackValue);

	int i;

	printf("Preparing data:\n");
	int data[LENGTH];
	for (i = 0; i < LENGTH; i++) {
		data[i] = i;
		printf("%d ", data[i]);
	}
	putchar(10);
	
	printf("\nEnqueuing:\n");

	for (i = 0; i < LENGTH; i++) {
		enqueue(Q, data + i);
		showQueue(Q, &unpackValue);
	}
	
	printf("\nis empty? %s\n", queueIsEmpty(Q) ? "True" : "False");
	
	printf("\nDequeuing:\n");\
	for (i = 0; i < LENGTH; i++) {
		int *dataPtr = (int *)dequeue(Q);
		printf("\nelement dequeued: %d\n", *dataPtr);
		showQueue(Q, &unpackValue);
	}

	printf("\nis empty? %s\n", queueIsEmpty(Q) ? "True" : "False");
	
	dropQueue(Q);
	
	return 0;
}