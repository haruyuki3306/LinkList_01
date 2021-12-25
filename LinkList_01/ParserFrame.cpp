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
	parser->receiveData = createQueueLinear();//数据区分配空间
	parser->frameHead = head;
	parser->frameTail = NULL;
	parser->headLength = headSize;//计算帧头长度
	if (type == HEAD_AND_TAIL)
	{
		if (tail == NULL)//没有帧尾
		{
			parser->tailLength = 0;
		}
		else//有帧尾
		{
		parser->frameTail = tail;
			parser->tailLength = tailSize;//计算帧尾长度
		}

	}
	else
	{
		parser->tailLength = 0;
	}
	parser->result = RESULT_FALSE;
	parser->dataLength = 0;
	parser->rStatus = PROC_IDLE;
	parser->ctn = 0;//计数器清0
	parser->dataFrame = createQueueLinear();//数据区分配空间
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
	while (!isQueueLinearEmpty(parser->receiveData) && parser->result == RESULT_FALSE)//数据缓冲区非空并且没有解释完一帧数据
	{
		dequeueLinear(parser->receiveData, &temp);
		switch (parser->rStatus)
		{
		case PROC_IDLE://空闲状态
			if (temp == parser->frameHead[0])//空闲状态只要关注帧头的起始字节
			{
				//enqueueLinear(parser->dataFrame, &temp);//
				if (parser->headLength == 1)
				{
					parser->rStatus = PROC_DATA;//帧头长度只有1那么跳到数据解释部分
					parser->ctn = 0;
				}
				else
				{
					parser->rStatus = PROC_HEAD;//帧头长度不只1那么继续解释帧头部分
					parser->ctn = 1;
				}
			}
			break;
		case PROC_HEAD://帧头部分
			if (temp == parser->frameHead[parser->ctn])
			{
				parser->ctn = parser->ctn + 1;
				if (parser->ctn == parser->headLength)//帧头解释完毕
				{
					parser->rStatus = PROC_DATA;
					parser->ctn = 0;
				}
			}
			else
			{
				//进入这里说明只解释到帧头起始字节，但后面的不符合，那么要重置解释器以便重新来过
				parser->rStatus = PROC_IDLE;
				parser->ctn = 0;
			}
			break;
		case PROC_DATA://数据解释部分
			switch (parser->fType)
			{
			case HEAD_AND_TAIL://头尾模式，帧头+数据+校验+帧尾
				if (temp == parser->frameTail[0])//数据与帧尾起始字节相同
				{
					if (parser->tailLength == 1)//帧尾只有1字节
					{
						//进入这里说明一帧数据解释完成
						parser->ctn = 0;
						parser->rStatus = PROC_IDLE;
						parser->result = RESULT_TRUE;
					}
					else//帧尾不只1字节
					{
						parser->rStatus = PROC_TAIL;//进入帧尾部分
						parser->ctn = 1;
					}
				}
				else
				{
					enqueueLinear(parser->dataFrame, &temp);//将数据存起来
					parser->dataLength = parser->dataLength + 1;
				}
				break;
			case HEAD_AND_LENGTH://头长度模式，帧头+长度+数据+校验
				if (parser->ctn == 0)//数据部分起始字节
				{
					parser->ctn = temp;//存入数据长度
				}
				else
				{
					enqueueLinear(parser->dataFrame, &temp);//将数据存起来
					parser->dataLength = parser->dataLength + 1;
					if (parser->dataLength == parser->ctn)
					{
						//进入这里说明一帧数据解释完成
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
		case PROC_TAIL://帧尾部分
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
			else//后一个字节不是帧尾内容
			{
				//进入这里说明数据没有和帧尾完全吻合，那么就是数据中含有和帧尾相似的部分，要把这部分放回数据中
				int i;
				for (i = 0; i < parser->ctn; i++)
				{
					enqueueLinear(parser->dataFrame, (datatype *)&parser->frameTail[i]);
				}
				enqueueLinear(parser->dataFrame, &temp);//当前接收到的字节数据存起来
				parser->rStatus = PROC_DATA;
				parser->ctn = 0;
			}
			break;
		case PROC_OVER://处理完成
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
	if (analysisCompleted(parser))//数据解释完成
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
	parser->ctn = 0;//计数器清0
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