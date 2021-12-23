#include "LinkedList.h"
#include <stdlib.h>
#include <string.h>

LinkedList *createLinkedList(int nodeSize)
{
	LinkedList *list;
	list = (LinkedList *)malloc(sizeof(*list));//C编译器不需要类型强转，C++编译器需要
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
	newNode = (struct SINGLE_NODE *)malloc(sizeof(*newNode));//C编译器不需要类型强转，C++编译器需要
	if (newNode ==NULL)
	{
		return -1;
	}
	newNode->data = malloc(list->nodeSize);
	if (newNode->data==NULL)
	{
		return -2;
	}
	memcpy(newNode->data,data,list->nodeSize);//将数据存入新节点中
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
	* 辅助函数，在链表中找到一个节点
	*
	* list要操作的链表
	* keyWord，关键词，用于查找链表中的内容
	* func，回调函数，用于查找条件
	*/
	struct SINGLE_NODE *current;
	for (current= list->head.nextNode; current !=&list->head; current=current->nextNode)
	{
		if (func(keyWord,current)==0)//由回调函数处理查找的条件，只要返回0则表示条件成功
		{
			return current;//返回当前节点
		}
	}
	return &list->head;//没有查找到目标，返回头部节点。头部节点里的数据是空的，相当于是返回了空数据
}

void *nodeFind(LinkedList *list, const void *keyWord, int(*func)(const void*, const void *))
{
	return find(list,keyWord,func)->data;//直接将找到的节点里的数据返回
}

int nodeDelete(LinkedList *list, const void *keyWord, int(*func)(const void*, const void *))
{
	struct SINGLE_NODE *node;
	node = find(list,keyWord,func);
	if (node==&list->head)//如果找到了头部节点，说明是空数据
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
		free(current->data);//将节点中的数据所占的空间释放
		free(current);//将节点本身所占的空间释放
	}
	free(list);//将链表头所占的空间释放
}