#include "Queue2.h"
#include <stdlib.h>

QUEUE_L *createQueueLinear(void)
{
	QUEUE_L *queue;
	queue = (QUEUE_L*)malloc(sizeof(QUEUE_L));//C编译器不需要类型强转，C++编译器需要
	if (queue==NULL)
	{
		return NULL;
	}
	queue->head = 0;
	queue->tail = 0;
	return queue;
}

int enqueueLinear(QUEUE_L *queue, datatype *data)
{
	if (((queue->tail+1)%MAXSIZE)==queue->head)
	{
		return -1;
	}
	queue->tail = (queue->tail + 1)%MAXSIZE;
	queue->data[queue->tail] = *data;
	return 0;
}

int dequeueLinear(QUEUE_L *queue, datatype *container)
{
	if (isQueueLinearEmpty(queue))
	{
		return -1;
	}
	queue->head = (queue->head + 1) % MAXSIZE;
	*container = queue->data[queue->head];
	return 0;
}

void travelQueueLinear(QUEUE_L *queue, void(*func)(const void *))
{
	int i;
	if (isQueueLinearEmpty(queue))
	{
		return;
	}
	for (i = (queue->head+1)%MAXSIZE; i !=queue->tail+1; i=(i+1)%MAXSIZE)
	{
		func(&queue->data[i]);
	}
}

void clearQueueLinear(QUEUE_L *queue)
{
	queue->head = 0;
	queue->tail = 0;
}

int isQueueLinearEmpty(QUEUE_L *queue)
{
	return (queue->head == queue->tail);
}

void destroyQueueLinear(QUEUE_L *queue)
{
	free(queue);
}

