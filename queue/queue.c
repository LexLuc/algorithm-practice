#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef struct Node {
	int value;
	struct Node *next;
} nodeType;

typedef struct QueueRepr {
	int length;
	nodeType *head;
	nodeType *tail;
} QueueRepr;

// initialize a new empty Queue:
Queue newQueue(void) {
	Queue Q = malloc(sizeof(QueueRepr));			assert(Q != NULL);
	Q->length = 0;
	Q->head = NULL;
	Q->tail = NULL;
	
	return Q;
}

// check whether the Queue is empty:
bool queueIsEmpty(Queue Q) {
	return Q->length == 0;
}

// delete the Queue:
void dropQueue(Queue Q) {
	nodeType *node = Q->head;
	while (node != NULL) {
		Q->head = Q->head->next;
		free(node);
		node = Q->head;
	}
	free(Q);
}

// add new element at the end of the Queue:
void enqueue(Queue Q, int data) {
	nodeType *newNode = malloc(sizeof(nodeType));	assert(newNode != NULL);
	newNode->value = data;
	newNode->next = NULL;
	if (Q->tail == NULL) {
		Q->head = newNode;
		Q->tail = newNode;
	} else {
		Q->tail->next = newNode;
		Q->tail = newNode;
	}
	Q->length ++;
}

// remove the element at the beginning of the Queue:
int dequeue(Queue Q) {
	assert(Q->length > 0);
	nodeType *node = Q->head; 	// get node to be dequeued
	int data = node->value;		// get value of such node
	Q->head = Q->head->next;	// head point to next node
	if (Q->head == NULL)
		Q->tail = NULL;
	free(node);					// delete node in memory space
	Q->length --;
	
	return data;
}

int getLength(Queue Q) {
	return Q->length;
}

void showQueue(Queue Q) {
	printf("Show Queue:\nHead->");
	nodeType *node;
	for (node = Q->head; node != NULL; node = node->next)
		printf("-%d-", node->value);
	printf("<-Tail\n\n");
}

