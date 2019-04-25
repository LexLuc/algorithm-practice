// Queue ADT interface
#include <stdbool.h>

typedef struct QueueRepr *Queue;

Queue newQueue(void);
bool queueIsEmpty(Queue);
void dropQueue(Queue);
void enqueue(Queue, void *value); 	// add element at the tail
void *dequeue(Queue);			    // remove element at the head 
int getLength(Queue);
void showQueue(Queue, void (*unpackValue)(void *value));
