#include "Queue.h"

QUEUE *createQueue(int dataSize)
{
	return createLinkedList(dataSize);
}

int enqueue(QUEUE *queue, void *data)
{
	/**
	*��Ϊ�����ǵ���nodeFetch����ɾ�������һ��Ԫ�أ�����
	*�������ֻ��������β�����һ��Ԫ�غ����
	*/
	return nodeInsert(queue, data, BACK);
}

static int  alwawsMatch(const void *p1, const void *p2)
{
	/**
	* brief  ��ȫƥ�亯��
	* param  ͨ������ p1,p2
	* retval 0
	*/
	return 0;
}

int dequeue(QUEUE *queue, void *data)
{
	/**
	*��ΪnodeFetch�����Ǵ�����ͷ��ʼ�����ģ�������Ϊ��
	*���Ļص��������Ƿ�����ֵ����ô�ͻ�õ�����ĵ�һ��Ԫ��
	*/
	return nodeFetch(queue, (void*)0, alwawsMatch, data);
}

void clearQueue(QUEUE *queue)
{
	struct SINGLE_NODE *current;
	for (current = queue->head.nextNode; current!=&queue->head; current=queue->head.nextNode)//ȡ�ýڵ�ָ��һ�����ڵ������ȥֱ�����
	{
		nodeDelete(queue, (void*)0, alwawsMatch);//ɾ��ͷ����һ���ڵ�
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