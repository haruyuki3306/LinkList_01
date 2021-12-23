#pragma once
#include "Queue.h"

typedef enum FRAME_TYPE
{
	HEAD_AND_TAIL,//ͷβģʽ��֡ͷ+����+У��+֡β
	HEAD_AND_LENGTH//ͷ����ģʽ��֡ͷ+����+����+У��
}FrameType;//����֡����

typedef enum RESULT
{
	RESULT_FALSE=1,
	RESULT_TRUE
}ParserResult;

typedef struct DATA_PARSER
{
	QUEUE *receiveData;//���յ���֡����
	void * frameHead;//֡ͷ
	void * frameTail;//֡β
	void * dataFrame;//���ͳ�������
	ParserResult result;//���ͽ��
	int dataLength;//֡���ݳ���
	FrameType fType;//֡����
}DataParser;

//typedef struct PARSER_HEAD
//{
//	int size;//֡�е������ݵĴ�С������1�ֽڣ�2�ֽڣ�4�ֽ�
//	FrameType fType;//֡����
//}ParserHead;

/**
* @brief  ����������
*
* @param  FrameType type ������Ҫ���͵�֡����
* @param  int size ֡�е������ݵĴ�С������1�ֽڣ�2�ֽڣ�4�ֽ�
* @param  void *head ֡ͷ
* @param  void *tail ֡β�����û��ʹ��Ҫ����void*
* @retval DataParser * �������Ľ�����
*/
DataParser *createDataParser(FrameType type,int size,void *head,void *tail);

int putData(DataParser *parser,void *data);

int analysisCompleted(DataParser *parser);

int getDataFrame(DataParser *parser,void *data);

void destroyDataParser(DataParser *parser);

