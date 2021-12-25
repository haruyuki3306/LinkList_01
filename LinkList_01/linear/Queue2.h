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
#define MAXSIZE 32
typedef unsigned char datatype; //������װ����������
typedef struct QUEUE_LINEAR
{
	datatype data[MAXSIZE];//����
	int head;//ͷ
	int tail;//β
}QUEUE_L;
/**
* @brief  ��������
*
* @param  None
* @retval QUEUE * �������Ķ���
*/
QUEUE_L *createQueueLinear(void);
/**
* @brief  �������
*
* @param  QUEUE *queue Ҫ�����Ķ���
* @param  datatype *data Ҫ��ӵ�����
* @retval ����������ɹ�����0��ʧ�ܷ���-1
*/
int enqueueLinear(QUEUE_L *queue,datatype *data);
/**
* @brief  ���ݳ���
*
* @param  QUEUE *queue Ҫ�����Ķ���
* @param  datatype *container ���ӵ����ݴ�ŵ�����
* @retval ����������ɹ�����0��ʧ�ܷ���-1
*/
int dequeueLinear(QUEUE_L *queue,datatype *container);
/**
* @brief  �����Ƿ�Ϊ��
*
* @param  QUEUE *queue Ҫ�����Ķ���
* @retval �������������Ϊ�շ���1�����зǿշ���0
*/
int isQueueLinearEmpty(QUEUE_L *queue);
/**
* @brief  ���������е�Ԫ��
*
* @param  QUEUE *queue Ҫ�����Ķ���
* @param  func���ص����������ڸ���������ָ�������ķ�ʽ
* @retval None
*/
void travelQueueLinear(QUEUE_L *queue,void (*func)(const void *));
/**
* @brief  ��ն��У������ͷſռ�
*
* @param  QUEUE *queue Ҫ�����Ķ���
* @retval None
*/
void clearQueueLinear(QUEUE_L *queue);
/**
* @brief  ���ٶ��У���գ��ͷſռ�
*
* @param  QUEUE *queue Ҫ�����Ķ���
* @retval None
*/
void destroyQueueLinear(QUEUE_L *queue);

#endif // !__QUEUE_H__
