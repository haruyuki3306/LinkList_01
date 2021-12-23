#pragma once
#include "Queue.h"

#define frameHead_H 0x5A //帧头高字节
#define frameHead_L 0xA5 //帧头低字节

typedef enum RESULT
{
	RESULT_FALSE,
	RESULT_TRUE
}ParserResult;

typedef struct DATA_PARSER
{
	QUEUE *receiveData;//接收到的帧数据
	void * frameHead;//帧头
	void * frameTail;//帧尾
	void * dataFrame;//解释出的数据
	ParserResult result;//解释结果
}DataParser;

DataParser *createDataParser(int size);

void destroyDataParser(DataParser *parser);

