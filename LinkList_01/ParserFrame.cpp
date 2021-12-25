#include "ParserFrame.h"
#include <stdlib.h>
#include <string.h>

DataParser *createDataParser(FrameType type, datatype *head, int headSize, datatype *tail, int tailSize)
{
	DataParser *parser;
	parser = (DataParser *)malloc(sizeof(DataParser));
	if (parser == NULL)
	{
		return NULL;
	}

	parser->fType = type;
	parser->receiveData = createQueueLinear();//����������ռ�
	parser->frameHead = head;
	parser->frameTail = NULL;
	parser->headLength = headSize;//����֡ͷ����
	if (type == HEAD_AND_TAIL)
	{
		if (tail == NULL)//û��֡β
		{
			parser->tailLength = 0;
		}
		else//��֡β
		{
		parser->frameTail = tail;
			parser->tailLength = tailSize;//����֡β����
		}

	}
	else
	{
		parser->tailLength = 0;
	}
	parser->result = RESULT_FALSE;
	parser->dataLength = 0;
	parser->rStatus = PROC_IDLE;
	parser->ctn = 0;//��������0
	parser->dataFrame = createQueueLinear();//����������ռ�
	return parser;
}

int putDataToParser(DataParser *parser, datatype *data)
{
	if (data == NULL || parser == NULL)
	{
		return -1;
	}
	enqueueLinear(parser->receiveData, data);
	return 0;
}

int analysisCompleted(DataParser *parser)
{
	if (parser->result == RESULT_TRUE)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int analysisData(DataParser *parser)
{
	datatype temp;
	if (parser == NULL)
	{
		return -1;
	}
	while (!isQueueLinearEmpty(parser->receiveData) && parser->result == RESULT_FALSE)//���ݻ������ǿղ���û�н�����һ֡����
	{
		dequeueLinear(parser->receiveData, &temp);
		switch (parser->rStatus)
		{
		case PROC_IDLE://����״̬
			if (temp == parser->frameHead[0])//����״ֻ̬Ҫ��ע֡ͷ����ʼ�ֽ�
			{
				//enqueueLinear(parser->dataFrame, &temp);//
				if (parser->headLength == 1)
				{
					parser->rStatus = PROC_DATA;//֡ͷ����ֻ��1��ô�������ݽ��Ͳ���
					parser->ctn = 0;
				}
				else
				{
					parser->rStatus = PROC_HEAD;//֡ͷ���Ȳ�ֻ1��ô��������֡ͷ����
					parser->ctn = 1;
				}
			}
			break;
		case PROC_HEAD://֡ͷ����
			if (temp == parser->frameHead[parser->ctn])
			{
				parser->ctn = parser->ctn + 1;
				if (parser->ctn == parser->headLength)//֡ͷ�������
				{
					parser->rStatus = PROC_DATA;
					parser->ctn = 0;
				}
			}
			else
			{
				//��������˵��ֻ���͵�֡ͷ��ʼ�ֽڣ�������Ĳ����ϣ���ôҪ���ý������Ա���������
				parser->rStatus = PROC_IDLE;
				parser->ctn = 0;
			}
			break;
		case PROC_DATA://���ݽ��Ͳ���
			switch (parser->fType)
			{
			case HEAD_AND_TAIL://ͷβģʽ��֡ͷ+����+У��+֡β
				if (temp == parser->frameTail[0])//������֡β��ʼ�ֽ���ͬ
				{
					if (parser->tailLength == 1)//֡βֻ��1�ֽ�
					{
						//��������˵��һ֡���ݽ������
						parser->ctn = 0;
						parser->rStatus = PROC_IDLE;
						parser->result = RESULT_TRUE;
					}
					else//֡β��ֻ1�ֽ�
					{
						parser->rStatus = PROC_TAIL;//����֡β����
						parser->ctn = 1;
					}
				}
				else
				{
					enqueueLinear(parser->dataFrame, &temp);//�����ݴ�����
					parser->dataLength = parser->dataLength + 1;
				}
				break;
			case HEAD_AND_LENGTH://ͷ����ģʽ��֡ͷ+����+����+У��
				if (parser->ctn == 0)//���ݲ�����ʼ�ֽ�
				{
					parser->ctn = temp;//�������ݳ���
				}
				else
				{
					enqueueLinear(parser->dataFrame, &temp);//�����ݴ�����
					parser->dataLength = parser->dataLength + 1;
					if (parser->dataLength == parser->ctn)
					{
						//��������˵��һ֡���ݽ������
						parser->ctn = 0;
						parser->rStatus = PROC_IDLE;
						parser->result = RESULT_TRUE;
					}
				}
				break;
			default:
				break;
			}
			break;
		case PROC_TAIL://֡β����
			if (temp == parser->frameTail[parser->ctn])
			{
				parser->ctn = parser->ctn + 1;
				if (parser->ctn == parser->tailLength)
				{
					parser->ctn = 0;
					parser->rStatus = PROC_IDLE;
					parser->result = RESULT_TRUE;
				}
			}
			else//��һ���ֽڲ���֡β����
			{
				//��������˵������û�к�֡β��ȫ�Ǻϣ���ô���������к��к�֡β���ƵĲ��֣�Ҫ���ⲿ�ַŻ�������
				int i;
				for (i = 0; i < parser->ctn; i++)
				{
					enqueueLinear(parser->dataFrame, (datatype *)&parser->frameTail[i]);
				}
				enqueueLinear(parser->dataFrame, &temp);//��ǰ���յ����ֽ����ݴ�����
				parser->rStatus = PROC_DATA;
				parser->ctn = 0;
			}
			break;
		case PROC_OVER://�������
			break;
		default:
			break;
		}
	}
	return 0;
}

int getDataFrame(DataParser *parser, QUEUE_L *data)
{
	if (parser == NULL || data == NULL)
	{
		return -1;
	}
	if (analysisCompleted(parser))//���ݽ������
	{
		memcpy(data, parser->dataFrame, sizeof(*parser->dataFrame));
		return 0;
	}
	else
	{
		return -2;
	}
}

void resetDataParser(DataParser *parser)
{
	//clearQueueLinear(parser->receiveData);
	parser->result = RESULT_FALSE;
	parser->dataLength = 0;
	parser->rStatus = PROC_IDLE;
	parser->ctn = 0;//��������0
	clearQueueLinear(parser->dataFrame);

}

void destroyDataParser(DataParser *parser)
{
	if (parser == NULL)
	{
		return;
	}
	destroyQueueLinear(parser->receiveData);
	destroyQueueLinear(parser->dataFrame);
	free(parser);
}