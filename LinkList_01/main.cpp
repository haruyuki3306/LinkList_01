//#include "LinkedList.h"
//#include "linear\Queue2.h"
#include "ParserFrame.h"
#include <stdio.h>
#include <windows.system.h>

#if 0

struct SCORE
{
	int id;
	char name[32];
	int math;
	int chinese;
};

#endif // 0


#if 0

void myprintf(const void * data)
{
	printf_s("%s\n", ((SCORE*)data)->name);
	printf_s("id=%d\n", ((SCORE*)data)->id);
	printf_s("math=%d\n", ((SCORE*)data)->math);
	printf_s("chinese=%d\n", ((SCORE*)data)->chinese);
	printf_s("\n");
}
int compare(const void *d1, const void *d2)
{
	struct SCORE *stu1;
	struct SINGLE_NODE *stu2;
	stu1 = (SCORE*)d1;
	stu2 = (SINGLE_NODE *)d2;
	/*printf_s("stu1:%d\n", stu1->id);
	printf_s("stu2:%d\n",((SCORE*)(stu2->data))->id);*/
	if (stu1->id == ((SCORE*)(stu2->data))->id)
	{
		return 0;
	}
	return -1;
}

#endif // 0

void printQueue(const void *data)
{
#if 0
	printf_s("id:%d\n", ((SCORE*)data)->id);
	printf_s("math:%d\n", ((SCORE*)data)->math);
	printf_s("chinese:%d\n", ((SCORE*)data)->chinese);
	printf_s("name:%s\n", ((SCORE*)data)->name);
#endif // 0
	printf_s("%x\n", *(datatype *)data);
}

int main(void)
{
#if 0

	LinkedList *linked, *linked2;
	struct SCORE student1, student2, student3, student4, student5, student6, student7, student8, student9;
	student1.id = 1;
	student1.math = rand() % 100;
	student1.chinese = rand() % 100;
	strcpy_s(student1.name, "xianyu");
	student2.id = 2;
	student2.math = rand() % 100;
	student2.chinese = rand() % 100;
	strcpy_s(student2.name, "yufengting");
	student3.id = 3;
	student3.math = rand() % 100;
	student3.chinese = rand() % 100;
	strcpy_s(student3.name, "yating");
	student4.id = 4;
	student4.math = rand() % 100;
	student4.chinese = rand() % 100;
	strcpy_s(student4.name, "fanlisheng");
	student6.id = 6;
	student6.math = rand() % 100;
	student6.chinese = rand() % 100;
	strcpy_s(student6.name, "denglixin");
	student7.id = 7;
	student7.math = rand() % 100;
	student7.chinese = rand() % 100;
	strcpy_s(student7.name, "dangyuan");
	student8.id = 8;
	student8.math = rand() % 100;
	student8.chinese = rand() % 100;
	strcpy_s(student8.name, "xingyang");
	student9.id = 9;
	student9.math = rand() % 100;
	student9.chinese = rand() % 100;
	strcpy_s(student9.name, "meiling");

	linked = createLinkedList(sizeof(SCORE));
	printf_s("test1 insert.........\n");
	nodeInsert(linked, &student1, BACK);
	nodeInsert(linked, &student2, BACK);
	nodeInsert(linked, &student3, BACK);
	nodeInsert(linked, &student4, BACK);
	travelLinkedList(linked, myprintf);
	printf_s("test1 delete.........\n");
	nodeDelete(linked, &student2, compare);
	travelLinkedList(linked, myprintf);
	printf_s("test1 fetch.........\n");
	nodeFetch(linked, &student4, compare, &student5);
	printf_s("stu5-name:=%s\n", student5.name);
	printf_s("stu5-id:=%d\n", student5.id);
	printf_s("stu5-math:=%d\n", student5.math);
	printf_s("stu5-chinese:=%d\n", student5.chinese);
	travelLinkedList(linked, myprintf);
	linked2 = createLinkedList(sizeof(SCORE));
	printf_s("test2 insert.........\n");
	nodeInsert(linked2, &student6, BACK);
	nodeInsert(linked2, &student7, BACK);
	nodeInsert(linked2, &student8, BACK);
	nodeInsert(linked2, &student9, BACK);
	travelLinkedList(linked2, myprintf);
	printf_s("test2 delete.........\n");
	nodeDelete(linked2, &student7, compare);
	travelLinkedList(linked2, myprintf);
	printf_s("test2 fetch.........\n");
	nodeFetch(linked2, &student8, compare, &student5);
	printf_s("stu5-name:=%s\n", student5.name);
	printf_s("stu5-id:=%d\n", student5.id);
	printf_s("stu5-math:=%d\n", student5.math);
	printf_s("stu5-chinese:=%d\n", student5.chinese);
	travelLinkedList(linked2, myprintf);
	destroyLinkedList(linked);
	destroyLinkedList(linked2);
#endif // 0

#if 0

	QUEUE *qu1, *qu2;
	struct SCORE stu1, stu2, stu3, stu4, stu5, stu6, stu7, stu8, stu9;
	stu1.id = 1;
	stu1.math = rand() % 100;
	stu1.chinese = rand() % 100;
	strcpy_s(stu1.name, "LiLei");

	stu2.id = 2;
	stu2.math = rand() % 100;
	stu2.chinese = rand() % 100;
	strcpy_s(stu2.name, "HanMeimei");

	stu3.id = 3;
	stu3.math = rand() % 100;
	stu3.chinese = rand() % 100;
	strcpy_s(stu3.name, "HuYifei");

	stu4.id = 4;
	stu4.math = rand() % 100;
	stu4.chinese = rand() % 100;
	strcpy_s(stu4.name, "ChenMeijia");

	qu1 = createQueue(sizeof(SCORE));
	printf_s("test1 enqueue...........\n");
	enqueue(qu1, &stu1);
	enqueue(qu1, &stu2);
	enqueue(qu1, &stu3);
	enqueue(qu1, &stu4);
	travelQueue(qu1, printQueue);
	printf_s("test1 dequeue..........\n");
	dequeue(qu1, &stu9);
	travelQueue(qu1, printQueue);
	dequeue(qu1, &stu8);
	dequeue(qu1, &stu7);
	dequeue(qu1, &stu6);

	qu2 = createQueue(sizeof(SCORE));
	printf_s("test2 enqueue............\n");
	enqueue(qu2, &stu6);
	enqueue(qu2, &stu7);
	enqueue(qu2, &stu8);
	enqueue(qu2, &stu9);
	travelQueue(qu2, printQueue);
	printf_s("test2 is empty............\n");
	printf_s("is empty:%d\n", isEmptyQueue(qu2));
	printf_s("test2 clear............\n");
	clearQueue(qu2);
	printf_s("is empty:%d\n", isEmptyQueue(qu2));
	//travelQueue(qu2,printQueue);


	destroyQueue(qu1);
	destroyQueue(qu2);
#endif // 0

#if 0

	QUEUE_L *que1, *que2;
	datatype arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13 };
	datatype temp;
	int i;
	que1 = createQueueLinear();
	printf_s("enqueue..........\n");
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		enqueueLinear(que1, &arr[i]);
	}

	travelQueueLinear(que1, printQueue);

	printf_s("dequeue.......\n");
	dequeueLinear(que1, &temp);
	printf_s("de--->%d\n", temp);
	dequeueLinear(que1, &temp);
	printf_s("de--->%d\n", temp);
	dequeueLinear(que1, &temp);
	printf_s("de--->%d\n", temp);
	dequeueLinear(que1, &temp);
	printf_s("de--->%d\n", temp);
	dequeueLinear(que1, &temp);
	printf_s("de--->%d\n", temp);
	dequeueLinear(que1, &temp);
	printf_s("de--->%d\n", temp);
	printf_s("after dequeue.......\n");
	travelQueueLinear(que1, printQueue);
	printf_s("clear.......\n");
	clearQueueLinear(que1);
	travelQueueLinear(que1, printQueue);
	printf_s("end clear.......\n");

	que2 = createQueueLinear();
	printf_s("enqueue 2..........\n");
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		enqueueLinear(que2, &arr[i]);
	}

	travelQueueLinear(que2, printQueue);

	printf_s("dequeue 2.......\n");
	dequeueLinear(que2, &temp);
	printf_s("de--->%d\n", temp);
	dequeueLinear(que2, &temp);
	printf_s("de--->%d\n", temp);
	dequeueLinear(que2, &temp);
	printf_s("de--->%d\n", temp);
	dequeueLinear(que2, &temp);
	printf_s("de--->%d\n", temp);
	dequeueLinear(que2, &temp);
	printf_s("de--->%d\n", temp);
	dequeueLinear(que2, &temp);
	printf_s("de--->%d\n", temp);
	printf_s("after dequeue 2.......\n");
	travelQueueLinear(que2, printQueue);
	printf_s("clear 2.......\n");
	clearQueueLinear(que2);
	travelQueueLinear(que2, printQueue);
	printf_s("end clear 2.......\n");

	destroyQueueLinear(que1);
	destroyQueueLinear(que2);
#endif // 0
	int i, temp;
	DataParser *parser1,*parser2;
	QUEUE_L queue1,queue2;
	datatype FRAME_HEAD[] = { 0x5A,0xA5 };
	datatype FRAME_TAIL[] = { 0xCC,0x3C,0xAC,0xCA };
	datatype datas[] = { 0x5A,0xA5,0x82,0x14,0x15,0x16,0xCC,0x3C,0x17,0x18,0xCC,0x3C,0xAC,0xCA,0x20,0x31,0x5A,0xA5,0x82,0x33,0x44,0x55,0x56,0x57,0x58,0xCC,0x3C,0xAC,0xCA };
	datatype datas2[] = { 0x5A,0xA5,0x07,0x82,0x13,0x14,0x5A,0xA5,0x15,0x16,0x17,0x18,0xCC, 0x5A,0xA5,0x04,0x82,0x33,0x34,0x35,0x36 };
	parser1 = createDataParser(HEAD_AND_TAIL, FRAME_HEAD, sizeof(FRAME_HEAD), FRAME_TAIL, sizeof(FRAME_TAIL));
	parser2 = createDataParser(HEAD_AND_LENGTH, FRAME_HEAD, sizeof(FRAME_HEAD), (datatype*)0, 0);

	printf_s("start test............\n");
	printf_s("put data............\n");
	for (i = 0; i < sizeof(datas) / sizeof(*datas); i++)
	{
		putDataToParser(parser1, (datatype*)&datas[i]);
	}
	printf_s("after put............\n");
	travelQueueLinear(parser1->receiveData, printQueue);
	printf_s("parser..........\n");
	analysisData(parser1);
	if ((temp = getDataFrame(parser1, &queue1)) == 0)
	{
		printf_s("parser succes..........\n");
	}
	else
	{
		printf_s("parser fail!!!..........\n");
		printf_s("parser fail code:%d\n", temp);

	}
	printf_s("after parser..........\n");

	travelQueueLinear(&queue1, printQueue);
	resetDataParser(parser1);
	clearQueueLinear(&queue1);
	printf_s("parser..........\n");
	analysisData(parser1);
	if ((temp = getDataFrame(parser1, &queue1)) == 0)
	{
		printf_s("parser succes..........\n");
	}
	else
	{
		printf_s("parser fail!!!..........\n");
		printf_s("parser fail code:%d\n", temp);

	}
	printf_s("after parser..........\n");

	travelQueueLinear(&queue1, printQueue);



	printf_s("start test2............\n");
	printf_s("put data 2............\n");
	for (i = 0; i < sizeof(datas2) / sizeof(*datas2); i++)
	{
		putDataToParser(parser2, (datatype*)&datas2[i]);
	}
	printf_s("after put 2............\n");
	travelQueueLinear(parser2->receiveData, printQueue);
	printf_s("parser 2..........\n");
	analysisData(parser2);
	if ((temp = getDataFrame(parser2, &queue2)) == 0)
	{
		printf_s("parser succes 2..........\n");
	}
	else
	{
		printf_s("parser 2 fail!!!..........\n");
		printf_s("parser 2 fail code:%d\n", temp);

	}
	printf_s("after parser 2..........\n");

	travelQueueLinear(&queue2, printQueue);
	resetDataParser(parser2);
	clearQueueLinear(&queue2);
	printf_s("parser 2..........\n");
	analysisData(parser2);
	if ((temp = getDataFrame(parser2, &queue2)) == 0)
	{
		printf_s("parser 2 succes..........\n");
	}
	else
	{
		printf_s("parser 2 fail!!!..........\n");
		printf_s("parser 2 fail code:%d\n", temp);

	}
	printf_s("after parser 2..........\n");

	travelQueueLinear(&queue2, printQueue);

	//printf_s("again..........\n");

	//resetDataParser(parser1);
	//clearQueueLinear(&queue1);
	//i = 0;
	///*for (i = 2; i < sizeof(datas) - 4; i++)
	//{
	//	datas[i] = 0x20 + i;
	//}*/
	//printf_s("put data start............\n");

	//for (i = 0; i < sizeof(datas) / sizeof(*datas); i++)
	//{
	//	printf_s("put data %d byte............\n", i);
	//	putDataToParser(parser1, (datatype*)&datas[i]);
	//	printf_s("parser..........\n");
	//	analysisData(parser1);
	//	if ((temp = getDataFrame(parser1, &queue1)) == 0)
	//	{
	//		printf_s("parser succes..........\n");
	//	}
	//	else
	//	{
	//		printf_s("parser fail!!!..........\n");
	//		printf_s("parser fail code:%d\n", temp);

	//	}
	//	printf_s("after parser..........\n");

	//	travelQueueLinear(&queue1, printQueue);
	//	Sleep(500);
	//}


	destroyDataParser(parser1);

	system("pause");
}