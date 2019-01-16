// Queue ADT interface
#include <stdbool.h>

typedef struct QueueRepr *Queue;

Queue newQueue(void);
bool queueIsEmpty(Queue);
void dropQueue(Queue);
void enqueue(Queue, int); 	// add element at the tail
int dequeue(Queue);			// remove element at the head 
int getLength(Queue);
void showQueue(Queue);
