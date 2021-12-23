#include "Queue.h"

QUEUE *createQueue(int dataSize)
{
	return createLinkedList(dataSize);
}

int enqueue(QUEUE *queue, void *data)
{
	/**
	*因为出队是调用nodeFetch函数删除链表第一个元素，所以
	*这里入队只能在链表尾部最后一个元素后插入
	*/
	return nodeInsert(queue, data, BACK);
}

static int  alwawsMatch(const void *p1, const void *p2)
{
	/**
	* brief  完全匹配函数
	* param  通用类型 p1,p2
	* retval 0
	*/
	return 0;
}

int dequeue(QUEUE *queue, void *data)
{
	/**
	*因为nodeFetch函数是从链表头开始遍历的，这里作为条
	*件的回调函数总是返回真值，那么就会得到链表的第一个元素
	*/
	return nodeFetch(queue, (void*)0, alwawsMatch, data);
}

void clearQueue(QUEUE *queue)
{
	struct SINGLE_NODE *current;
	for (current = queue->head.nextNode; current!=&queue->head; current=queue->head.nextNode)//取得节点指针一个个节点遍历下去直到最后
	{
		nodeDelete(queue, (void*)0, alwawsMatch);//删除头部第一个节点
	}
}

void travelQueue(QUEUE *queue, void(*func)(const void*))
{
	travelLinkedList(queue, func);
}

int isEmptyQueue(QUEUE *queue)
{
	return((queue->head.nextNode) == &(queue->head) && (queue->head.prevNode) == &queue->head);
}

void destroyQueue(QUEUE *queue)
{
	destroyLinkedList(queue);
}