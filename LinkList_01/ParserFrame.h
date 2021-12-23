#pragma once
#include "Queue.h"

#define frameHead_H 0x5A //֡ͷ���ֽ�
#define frameHead_L 0xA5 //֡ͷ���ֽ�

typedef enum RESULT
{
	RESULT_FALSE,
	RESULT_TRUE
}ParserResult;

typedef struct DATA_PARSER
{
	QUEUE *receiveData;//���յ���֡����
	void * frameHead;//֡ͷ
	void * frameTail;//֡β
	void * dataFrame;//���ͳ�������
	ParserResult result;//���ͽ��
}DataParser;

DataParser *createDataParser(int size);

void destroyDataParser(DataParser *parser);

