//#include "LinkedList.h"
#include "Queue.h"
#include <stdio.h>
#include <windows.system.h>
struct SCORE
{
	int id;
	char name[32];
	int math;
	int chinese;
};

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
	printf_s("id:%d\n", ((SCORE*)data)->id);
	printf_s("math:%d\n", ((SCORE*)data)->math);
	printf_s("chinese:%d\n",((SCORE*)data)->chinese);
	printf_s("name:%s\n", ((SCORE*)data)->name);
}

int main(void)
{
#if 0

	LinkedList *linked,*linked2;
	struct SCORE student1, student2, student3, student4,student5,student6, student7, student8, student9;
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
	nodeFetch(linked,&student4,compare, &student5);
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

	QUEUE *qu1,*qu2;
	struct SCORE stu1, stu2, stu3, stu4, stu5, stu6, stu7, stu8, stu9;
	stu1.id = 1;
	stu1.math = rand() % 100;
	stu1.chinese = rand() % 100;
	strcpy_s(stu1.name,"LiLei");
	
	stu2.id = 2;
	stu2.math = rand() % 100;
	stu2.chinese = rand() % 100;
	strcpy_s(stu2.name,"HanMeimei");

	stu3.id = 3;
	stu3.math = rand() % 100;
	stu3.chinese = rand() % 100;
	strcpy_s(stu3.name,"HuYifei");

	stu4.id = 4;
	stu4.math = rand() % 100;
	stu4.chinese = rand() % 100;
	strcpy_s(stu4.name,"ChenMeijia");

	qu1 = createQueue(sizeof(SCORE));
	printf_s("test1 enqueue...........\n");
	enqueue(qu1, &stu1);
	enqueue(qu1, &stu2);
	enqueue(qu1, &stu3);
	enqueue(qu1, &stu4);
	travelQueue(qu1, printQueue);
	printf_s("test1 dequeue..........\n");
	dequeue(qu1,&stu9);
	travelQueue(qu1, printQueue);
	dequeue(qu1, &stu8);
	dequeue(qu1, &stu7);
	dequeue(qu1,&stu6);

	qu2 = createQueue(sizeof(SCORE));
	printf_s("test2 enqueue............\n");
	enqueue(qu2, &stu6);
	enqueue(qu2, &stu7);
	enqueue(qu2, &stu8);
	enqueue(qu2,&stu9);
	travelQueue(qu2,printQueue);
	printf_s("test2 is empty............\n");
	printf_s("is empty:%d\n",isEmptyQueue(qu2));
	printf_s("test2 clear............\n");
	clearQueue(qu2);
	printf_s("is empty:%d\n",isEmptyQueue(qu2));
	//travelQueue(qu2,printQueue);


	destroyQueue(qu1);
	destroyQueue(qu2);

	system("pause");
}