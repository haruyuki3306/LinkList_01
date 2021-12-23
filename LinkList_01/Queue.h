#pragma once
#include "LinkedList.h"
typedef LinkedList QUEUE;
/**
* @brief  ��������
*
* @param  int dataSize ������ÿ��Ԫ�ش��������ݳ���
* @retval QUEUE * �������Ķ���
*/
QUEUE *createQueue(int dataSize);
/**
* @brief  �������
*
* @param  QUEUE *queue Ҫ�����Ķ���
* @param  void *data Ҫ������е�����
* @retval int ����������ɹ�����0��ʧ�ܷ���-1
*/
int enqueue(QUEUE *queue,void *data);
/**
* @brief  ���ݳ���
*
* @param  QUEUE *queue Ҫ�����Ķ���
* @param  void *data ������ŴӶ������ó���������
* @retval int ����������ɹ�����0��ʧ�ܷ���-1
*/
int dequeue(QUEUE *queue, void *data);
/**
* @brief  ��������
*
* @param  QUEUE *queue Ҫ�����Ķ���
* @retval None
*/
void travelQueue(QUEUE *queue, void(*func)(const void*));
/**
* @brief  �����Ƿ�Ϊ��
*
* @param  QUEUE *queue Ҫ�����Ķ���
* @retval int ����Ϊ�շ���1�����зǿշ���0
*/
int isEmptyQueue(QUEUE *queue);
/**
* @brief  ��ն���
*
* @param  QUEUE *queue Ҫ�����Ķ���
* @retval None
*/
void clearQueue(QUEUE *queue);
/**
* @brief  ��������
*
* @param  QUEUE *queue Ҫ�����Ķ���
* @retval None
*/
void destroyQueue(QUEUE *queue);

