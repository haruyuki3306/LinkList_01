#pragma once
#include "Queue.h"

typedef enum FRAME_TYPE
{
	HEAD_AND_TAIL,//头尾模式，帧头+数据+校验+帧尾
	HEAD_AND_LENGTH//头长度模式，帧头+长度+数据+校验
}FrameType;//数据帧类型

typedef enum RESULT
{
	RESULT_FALSE=1,
	RESULT_TRUE
}ParserResult;

typedef struct DATA_PARSER
{
	QUEUE *receiveData;//接收到的帧数据
	void * frameHead;//帧头
	void * frameTail;//帧尾
	void * dataFrame;//解释出的数据
	ParserResult result;//解释结果
	int dataLength;//帧数据长度
	FrameType fType;//帧类型
}DataParser;

//typedef struct PARSER_HEAD
//{
//	int size;//帧中单个数据的大小，比如1字节，2字节，4字节
//	FrameType fType;//帧类型
//}ParserHead;

/**
* @brief  创建解释器
*
* @param  FrameType type 解释器要解释的帧类型
* @param  int size 帧中单个数据的大小，比如1字节，2字节，4字节
* @param  void *head 帧头
* @param  void *tail 帧尾，如果没有使用要传入void*
* @retval DataParser * 所创建的解释器
*/
DataParser *createDataParser(FrameType type,int size,void *head,void *tail);

int putData(DataParser *parser,void *data);

int analysisCompleted(DataParser *parser);

int getDataFrame(DataParser *parser,void *data);

void destroyDataParser(DataParser *parser);

