#include "../linear/Queue.h"
#include <stdlib.h>

QUEUE *createQueue(void)
{
	QUEUE *queue;
	queue = (QUEUE*)malloc(sizeof(queue));//C编译器不需要类型强转，C++编译器需要
	if (queue==NULL)
	{
		return NULL;
	}
	queue->head = 0;
	queue->tail = 0;
	return queue;
}

int enqueue(QUEUE *queue, datatype *data)
{
	if (((queue->tail+1)%MAXSIZE)==queue->head)
	{
		return -1;
	}
	queue->tail = (queue->tail + 1)%MAXSIZE;
}

void clearQueue(QUEUE *queue)
{
	queue->head = 0;
	queue->tail = 0;
}

int isQueueEmpty(QUEUE *queue)
{
	return (queue->head == queue->tail);
}

void destroyQueue(QUEUE *queue)
{
	free(queue);
}

