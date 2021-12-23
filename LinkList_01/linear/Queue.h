/**
******************************************************************************
* @file    Queue.h
* @author  wumuxing
* @version 1.0
* @date    2020/12/1
* @note	   ���У�������ʵ�֣�����ֻ��װ�������͵����ݣ�����int char,����װ�ṹ����
*
******************************************************************************
*/

#ifndef __QUEUE_H__
#define __QUEUE_H__
#define MAXSIZE 24
typedef int datatype; //������װ����������
typedef struct QUEUE_LINEAR
{
	datatype data[MAXSIZE];//����
	int head;//ͷ
	int tail;//β
}QUEUE;
/**
* @brief  ��������
*
* @param  None
* @retval QUEUE * �������Ķ���
*/
QUEUE *createQueue(void);
/**
* @brief  �������
*
* @param  QUEUE *queue Ҫ�����Ķ���
* @param  datatype *data Ҫ��ӵ�����
* @retval ����������ɹ�����0��ʧ�ܷ���-1
*/
int enqueue(QUEUE *queue,datatype *data);
/**
* @brief  ���ݳ���
*
* @param  QUEUE *queue Ҫ�����Ķ���
* @param  datatype *container ���ӵ����ݴ�ŵ�����
* @retval ����������ɹ�����0��ʧ�ܷ���-1
*/
int dequeue(QUEUE *queue,datatype *container);
/**
* @brief  �����Ƿ�Ϊ��
*
* @param  QUEUE *queue Ҫ�����Ķ���
* @retval �������������Ϊ�շ���1�����зǿշ���0
*/
int isQueueEmpty(QUEUE *queue);
/**
* @brief  ���������е�Ԫ��
*
* @param  QUEUE *queue Ҫ�����Ķ���
* @param  func���ص����������ڸ���������ָ�������ķ�ʽ
* @retval None
*/
void travelQueue(QUEUE *queue,void (*func)(const void *));
/**
* @brief  ��ն��У������ͷſռ�
*
* @param  QUEUE *queue Ҫ�����Ķ���
* @retval None
*/
void clearQueue(QUEUE *queue);
/**
* @brief  ���ٶ��У���գ��ͷſռ�
*
* @param  QUEUE *queue Ҫ�����Ķ���
* @retval None
*/
void destroyQueue(QUEUE *queue);

#endif // !__QUEUE_H__
