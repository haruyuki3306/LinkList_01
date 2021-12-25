#pragma once
#include "linear/Queue2.h"

typedef enum FRAME_TYPE
{
	HEAD_AND_TAIL,//ͷβģʽ��֡ͷ+����+У��+֡β
	HEAD_AND_LENGTH//ͷ����ģʽ��֡ͷ+����+����+У��
}FrameType;//����֡����

typedef enum RESULT
{
	RESULT_FALSE=0,
	RESULT_TRUE
}ParserResult;

typedef enum RECEIVE_STATUS
{
	PROC_IDLE,//����
	PROC_HEAD,//����֡ͷ����
	PROC_DATA,//�������ݲ���
	PROC_TAIL,//����֡β����
	PROC_OVER//�������
}RStatus;

typedef struct DATA_PARSER
{
	QUEUE_L *receiveData;//���յ���֡���ݣ��൱�����ݻ�����
	datatype * frameHead;//֡ͷ
	datatype * frameTail;//֡β
	int headLength;//֡ͷ���ȣ���λ�ֽڡ�����headLength=2��֡ͷ����Ϊ2�ֽ�
	int tailLength;//֡β���ȣ���λ�ֽڡ�
	QUEUE_L * dataFrame;//���ͳ�������
	ParserResult result;//���ͽ��
	int dataLength;//֡���ݳ��ȡ�ȥ��֡ͷ֡β�ȸ����ֽ�ʣ�µĲ������ݳ���
	FrameType fType;//֡����
	RStatus rStatus;//������״̬
	int ctn;//�����ֽڼ���
}DataParser;

/**
* @brief  ����������
*
* @param  FrameType type ������Ҫ���͵�֡����
* @param  int size ֡�е������ݵĴ�С������1�ֽڣ�2�ֽڣ�4�ֽ�
* @param  datatype *head ֡ͷ  8λ���ȵ�ָ��
* @param  datatype *tail ֡β�����û��ʹ��Ҫ����(void*)0
* @retval DataParser * �������Ľ�����
*/
DataParser *createDataParser(FrameType type, datatype *head, int headSize, datatype *tail, int tailSize);

/**
* @brief  �����ݴ��������
*
* @param  DataParser *parser Ҫ�����Ľ�����
* @param  datatype *data Ҫ���������
* @retval int �����ɹ�����0��ʧ�ܷ���-1
* @note   ��Ϊ�ײ������������ݣ�����ÿ�δ��������ֻ����datatype����Ļ�������
*/
int putDataToParser(DataParser *parser, datatype *data);

/**
* @brief  ����һ֡�������
*
* @param  DataParser *parser Ҫ�����Ľ�����
* @retval int ������ɷ���1��δ��ɷ���0
*/
int analysisCompleted(DataParser *parser);

/**
* @brief  ��������
*
* @param  DataParser *parser Ҫ�����Ľ�����
* @retval int ���ͳɹ�����0��ʧ�ܷ���-1
* @note   ���ͳɹ���һ���ǽ�����ɣ���Ϊ�������е����ݲ�һ����������һ֡����
*/
int analysisData(DataParser *parser);

/**
* @brief  ��ȡ���ͳ�����֡����
*
* @param  DataParser *parser Ҫ�����Ľ�����
* @param  QUEUE_L *data ���ݴ��
* @retval int ��ȡ���ݳɹ�����0�������ʵ��Ϊ�շ���-1������δ������ɷ���-2
*/
int getDataFrame(DataParser *parser, QUEUE_L *data);

/**
* @brief  ���֡����
*
* @param  DataParser *parser Ҫ�����Ľ�����
* @retval None
* @note   ��λ�������е�״̬��ǣ�����Ѿ����ͳ���֡���ݡ����ջ������е����ݲ������
*/
void resetDataParser(DataParser *parser);

/**
* @brief  ���ٽ�����
*
* @param  DataParser *parser Ҫ�����Ľ�����
* @retval None
*/
void destroyDataParser(DataParser *parser);

