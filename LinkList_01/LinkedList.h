#pragma once

enum INSERT_MODE
{
	FRONT,
	BACK
};

//普通节点
struct SINGLE_NODE
{
	void *data;//数据内容
	struct SINGLE_NODE* prevNode;//前节点
	struct SINGLE_NODE* nextNode;//后节点
};
//头节点
typedef struct HEAD_NODE
{
	int nodeSize;//节点数据长度
	struct SINGLE_NODE head;//链表头
}LinkedList;
/**
* @brief  创建链表
*
* @param  int nodeSize链表每个节点中存贮的数据长度
* @retval LinkedList * 所创建的链表
*/
LinkedList *createLinkedList(int nodeSize);
/**
* @brief  在链表中插入一个节点
*
* @param  LinkedList *list 要操作的链表
* @param  void *data 要操作的数据，会存入到节点中
* @param  int mode 节点插入方式，1表示头部插入，2表示尾部插入
* @retval int 操作结果，0表示插入成功，-1表示节点分配空间失败，-2表示节点中的数据分配空间失败,-3表示节点插入失败
*/
int nodeInsert(LinkedList *list,void *data,int mode);
/**
* @brief  销毁链表
*
* @param  LinkedList *list要操作的链表
* @retval None
*/
void destroyLinkedList(LinkedList *list);
/**
* @brief  在链表中找到一个节点的数据
*
* @param  LinkedList *list要操作的链表
* @param  void *keyWord，关键词，用于查找链表中的内容
* @param  func，回调函数，用于查找条件
* @retval void * 查找到的数据
* @note   查找的原理：传入一个关键词keyWord，用这个关键词传入回调函数func，
*         回调函数中处理好关键词与链表的条件然后返回结果，根据回调函数的结果来
*         得到节点中的数据
*/
void *nodeFind(LinkedList *list, const void *keyWord, int(*func)(const void*, const void *));
/**
* @brief  在链表中删除一个节点,返回所删除节点中的数据。可以理解为拿取一个数据
*
* @param  LinkedList *list要操作的链表
* @param  void *keyWord，关键词，用于查找链表中的内容
* @param  func，回调函数，用于查找条件
* @param  void *backData，删除的节点中的数据
* @retval 操作的结果，成功返回0，失败返回-1
* @note   删除一个节点，被删除的这个节点中的数据存入backData中，可以通
*         过backData知道所删除的数据。
*         
*/
int nodeFetch(LinkedList *list, const void *keyWord, int(*func)(const void*, const void *),void *backData);
/**
* @brief  遍历链表中的元素
*
* @param  LinkedList *list要操作的链表
* @param  func，回调函数，用于辅助遍历，指定遍历的方式
* @retval None
*/
void travelLinkedList(LinkedList *list,void (*func)(const void*));
/**
* @brief  在链表中删除一个节点,不返回所删除节点中的数据
*
* @param  LinkedList *list要操作的链表
* @param  void *keyWord，关键词，用于查找链表中的内容
* @param  func，回调函数，用于查找条件
* @retval int 操作结果，成功返回0，失败返回-1
* @note   删除的原理：传入一个关键词keyWord，用这个关键词传入回调函数func，
*         回调函数中处理好关键词与链表的条件返回结果，根据回调函数的结果来
*         确定删除哪个节点
*/
int nodeDelete(LinkedList *list,const void *keyWord,int (*func)(const void*,const void *));
