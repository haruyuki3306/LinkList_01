#pragma once
#include "linear/Queue2.h"

typedef enum FRAME_TYPE
{
	HEAD_AND_TAIL,//头尾模式，帧头+数据+校验+帧尾
	HEAD_AND_LENGTH//头长度模式，帧头+长度+数据+校验
}FrameType;//数据帧类型

typedef enum RESULT
{
	RESULT_FALSE=0,
	RESULT_TRUE
}ParserResult;

typedef enum RECEIVE_STATUS
{
	PROC_IDLE,//空闲
	PROC_HEAD,//解释帧头部分
	PROC_DATA,//解释数据部分
	PROC_TAIL,//解释帧尾部分
	PROC_OVER//解释完成
}RStatus;

typedef struct DATA_PARSER
{
	QUEUE_L *receiveData;//接收到的帧数据，相当于数据缓冲区
	datatype * frameHead;//帧头
	datatype * frameTail;//帧尾
	int headLength;//帧头长度，单位字节。比如headLength=2，帧头长度为2字节
	int tailLength;//帧尾长度，单位字节。
	QUEUE_L * dataFrame;//解释出的数据
	ParserResult result;//解释结果
	int dataLength;//帧数据长度。去除帧头帧尾等辅助字节剩下的才是数据长度
	FrameType fType;//帧类型
	RStatus rStatus;//解释器状态
	int ctn;//解释字节计数
}DataParser;

/**
* @brief  创建解释器
*
* @param  FrameType type 解释器要解释的帧类型
* @param  int size 帧中单个数据的大小，比如1字节，2字节，4字节
* @param  datatype *head 帧头  8位长度的指针
* @param  datatype *tail 帧尾，如果没有使用要传入(void*)0
* @retval DataParser * 所创建的解释器
*/
DataParser *createDataParser(FrameType type, datatype *head, int headSize, datatype *tail, int tailSize);

/**
* @brief  将数据存入解释器
*
* @param  DataParser *parser 要操作的解释器
* @param  datatype *data 要存入的数据
* @retval int 操作成功返回0，失败返回-1
* @note   因为底层用数组存放数据，所以每次存入的数据只能是datatype定义的基本类型
*/
int putDataToParser(DataParser *parser, datatype *data);

/**
* @brief  解释一帧数据完成
*
* @param  DataParser *parser 要操作的解释器
* @retval int 解释完成返回1，未完成返回0
*/
int analysisCompleted(DataParser *parser);

/**
* @brief  解释数据
*
* @param  DataParser *parser 要操作的解释器
* @retval int 解释成功返回0，失败返回-1
* @note   解释成功不一定是解释完成，因为解释器中的数据不一定是完整的一帧数据
*/
int analysisData(DataParser *parser);

/**
* @brief  获取解释出来的帧数据
*
* @param  DataParser *parser 要操作的解释器
* @param  QUEUE_L *data 数据存放
* @retval int 获取数据成功返回0，传入的实参为空返回-1，数据未解释完成返回-2
*/
int getDataFrame(DataParser *parser, QUEUE_L *data);

/**
* @brief  清空帧数据
*
* @param  DataParser *parser 要操作的解释器
* @retval None
* @note   复位解释器中的状态标记，清空已经解释出的帧数据。接收缓冲区中的数据不会清除
*/
void resetDataParser(DataParser *parser);

/**
* @brief  销毁解释器
*
* @param  DataParser *parser 要操作的解释器
* @retval None
*/
void destroyDataParser(DataParser *parser);

