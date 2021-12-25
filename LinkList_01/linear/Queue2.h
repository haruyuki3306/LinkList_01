/**
******************************************************************************
* @file    Queue.h
* @author  wumuxing
* @version 1.0
* @date    2020/12/1
* @note	   队列，用数组实现，所以只能装基本类型的数据，比如int char,不能装结构类型
*
******************************************************************************
*/

#ifndef __QUEUE_H__
#define __QUEUE_H__
#define MAXSIZE 32
typedef unsigned char datatype; //队列里装的数据类型
typedef struct QUEUE_LINEAR
{
	datatype data[MAXSIZE];//数据
	int head;//头
	int tail;//尾
}QUEUE_L;
/**
* @brief  创建队列
*
* @param  None
* @retval QUEUE * 所创建的队列
*/
QUEUE_L *createQueueLinear(void);
/**
* @brief  数据入队
*
* @param  QUEUE *queue 要操作的队列
* @param  datatype *data 要入队的数据
* @retval 操作结果，成功返回0，失败返回-1
*/
int enqueueLinear(QUEUE_L *queue,datatype *data);
/**
* @brief  数据出队
*
* @param  QUEUE *queue 要操作的队列
* @param  datatype *container 出队的数据存放的容器
* @retval 操作结果，成功返回0，失败返回-1
*/
int dequeueLinear(QUEUE_L *queue,datatype *container);
/**
* @brief  队列是否为空
*
* @param  QUEUE *queue 要操作的队列
* @retval 操作结果，队列为空返回1，队列非空返回0
*/
int isQueueLinearEmpty(QUEUE_L *queue);
/**
* @brief  遍历队列中的元素
*
* @param  QUEUE *queue 要操作的队列
* @param  func，回调函数，用于辅助遍历，指定遍历的方式
* @retval None
*/
void travelQueueLinear(QUEUE_L *queue,void (*func)(const void *));
/**
* @brief  清空队列，不会释放空间
*
* @param  QUEUE *queue 要操作的队列
* @retval None
*/
void clearQueueLinear(QUEUE_L *queue);
/**
* @brief  销毁队列，清空，释放空间
*
* @param  QUEUE *queue 要操作的队列
* @retval None
*/
void destroyQueueLinear(QUEUE_L *queue);

#endif // !__QUEUE_H__
