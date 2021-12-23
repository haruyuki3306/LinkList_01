#pragma once
#include "LinkedList.h"
typedef LinkedList QUEUE;
/**
* @brief  创建队列
*
* @param  int dataSize 队列中每个元素存贮的数据长度
* @retval QUEUE * 所创建的队列
*/
QUEUE *createQueue(int dataSize);
/**
* @brief  数据入队
*
* @param  QUEUE *queue 要操作的队列
* @param  void *data 要放入队列的数据
* @retval int 操作结果，成功返回0，失败返回-1
*/
int enqueue(QUEUE *queue,void *data);
/**
* @brief  数据出队
*
* @param  QUEUE *queue 要操作的队列
* @param  void *data 用来存放从队列中拿出来的数据
* @retval int 操作结果，成功返回0，失败返回-1
*/
int dequeue(QUEUE *queue, void *data);
/**
* @brief  遍历队列
*
* @param  QUEUE *queue 要操作的队列
* @retval None
*/
void travelQueue(QUEUE *queue, void(*func)(const void*));
/**
* @brief  队列是否为空
*
* @param  QUEUE *queue 要操作的队列
* @retval int 队列为空返回1，队列非空返回0
*/
int isEmptyQueue(QUEUE *queue);
/**
* @brief  清空队列
*
* @param  QUEUE *queue 要操作的队列
* @retval None
*/
void clearQueue(QUEUE *queue);
/**
* @brief  队列销毁
*
* @param  QUEUE *queue 要操作的队列
* @retval None
*/
void destroyQueue(QUEUE *queue);

