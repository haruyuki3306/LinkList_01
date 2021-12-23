#include "LinkedList.h"
#include <stdlib.h>
#include <string.h>

LinkedList *createLinkedList(int nodeSize)
{
	LinkedList *list;
	list = (LinkedList *)malloc(sizeof(*list));//C����������Ҫ����ǿת��C++��������Ҫ
	if (list==NULL)
	{
		return NULL;
	}
	list->nodeSize = nodeSize;
	list->head.data = NULL;
	list->head.nextNode = &list->head;
	list->head.prevNode = &list->head;

	return list;
}

int nodeInsert(LinkedList *list, void *data, int mode)
{
	struct SINGLE_NODE *newNode;
	newNode = (struct SINGLE_NODE *)malloc(sizeof(*newNode));//C����������Ҫ����ǿת��C++��������Ҫ
	if (newNode ==NULL)
	{
		return -1;
	}
	newNode->data = malloc(list->nodeSize);
	if (newNode->data==NULL)
	{
		return -2;
	}
	memcpy(newNode->data,data,list->nodeSize);//�����ݴ����½ڵ���
	switch (mode)
	{
	case FRONT:
		newNode->prevNode = &list->head;
		newNode->nextNode = list->head.nextNode;
		break;
	case BACK:
		newNode->prevNode = list->head.prevNode;
		newNode->nextNode = &list->head;
		break;
	default:
		return -3;
	}
	newNode->prevNode->nextNode = newNode;
	newNode->nextNode->prevNode = newNode;
	return 0;
}

static struct SINGLE_NODE *find(LinkedList *list,const void *keyWord,int(*func)(const void *,const void *))
{
	/**
	* �������������������ҵ�һ���ڵ�
	*
	* listҪ����������
	* keyWord���ؼ��ʣ����ڲ��������е�����
	* func���ص����������ڲ�������
	*/
	struct SINGLE_NODE *current;
	for (current= list->head.nextNode; current !=&list->head; current=current->nextNode)
	{
		if (func(keyWord,current)==0)//�ɻص�����������ҵ�������ֻҪ����0���ʾ�����ɹ�
		{
			return current;//���ص�ǰ�ڵ�
		}
	}
	return &list->head;//û�в��ҵ�Ŀ�꣬����ͷ���ڵ㡣ͷ���ڵ���������ǿյģ��൱���Ƿ����˿�����
}

void *nodeFind(LinkedList *list, const void *keyWord, int(*func)(const void*, const void *))
{
	return find(list,keyWord,func)->data;//ֱ�ӽ��ҵ��Ľڵ�������ݷ���
}

int nodeDelete(LinkedList *list, const void *keyWord, int(*func)(const void*, const void *))
{
	struct SINGLE_NODE *node;
	node = find(list,keyWord,func);
	if (node==&list->head)//����ҵ���ͷ���ڵ㣬˵���ǿ�����
	{
		return -1;
	}
	else
	{
		node->prevNode->nextNode = node->nextNode;
		node->nextNode->prevNode = node->prevNode;
		free(node->data);
		free(node);
		return 0;
	}
}

int nodeFetch(LinkedList *list, const void *keyWord, int(*func)(const void*, const void *), void *backData)
{
	struct SINGLE_NODE *node;
	node = find(list,keyWord,func);
	if (node== &list->head)
	{
		return -1;
	}
	else
	{
		node->prevNode->nextNode = node->nextNode;
		node->nextNode->prevNode = node->prevNode;
		if (backData!=NULL)
		{
			memcpy(backData,node->data,list->nodeSize);
		}
		free(node->data);
		free(node);
		return 0;
	}
}

void travelLinkedList(LinkedList *list, void(*func)(const void*))
{
	struct SINGLE_NODE *current;
	for ( current = list->head.nextNode; current != &list->head; current=current->nextNode)
	{
		func(current->data);
	}
}

void destroyLinkedList(LinkedList *list)
{
	struct SINGLE_NODE *current, *next;
	for ( current = list->head.nextNode; current!=&list->head; current=next)
	{
		next = current->nextNode;
		free(current->data);//���ڵ��е�������ռ�Ŀռ��ͷ�
		free(current);//���ڵ㱾����ռ�Ŀռ��ͷ�
	}
	free(list);//������ͷ��ռ�Ŀռ��ͷ�
}