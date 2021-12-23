#pragma once

enum INSERT_MODE
{
	FRONT,
	BACK
};

//��ͨ�ڵ�
struct SINGLE_NODE
{
	void *data;//��������
	struct SINGLE_NODE* prevNode;//ǰ�ڵ�
	struct SINGLE_NODE* nextNode;//��ڵ�
};
//ͷ�ڵ�
typedef struct HEAD_NODE
{
	int nodeSize;//�ڵ����ݳ���
	struct SINGLE_NODE head;//����ͷ
}LinkedList;
/**
* @brief  ��������
*
* @param  int nodeSize����ÿ���ڵ��д��������ݳ���
* @retval LinkedList * ������������
*/
LinkedList *createLinkedList(int nodeSize);
/**
* @brief  �������в���һ���ڵ�
*
* @param  LinkedList *list Ҫ����������
* @param  void *data Ҫ���������ݣ�����뵽�ڵ���
* @param  int mode �ڵ���뷽ʽ��1��ʾͷ�����룬2��ʾβ������
* @retval int ���������0��ʾ����ɹ���-1��ʾ�ڵ����ռ�ʧ�ܣ�-2��ʾ�ڵ��е����ݷ���ռ�ʧ��,-3��ʾ�ڵ����ʧ��
*/
int nodeInsert(LinkedList *list,void *data,int mode);
/**
* @brief  ��������
*
* @param  LinkedList *listҪ����������
* @retval None
*/
void destroyLinkedList(LinkedList *list);
/**
* @brief  ���������ҵ�һ���ڵ������
*
* @param  LinkedList *listҪ����������
* @param  void *keyWord���ؼ��ʣ����ڲ��������е�����
* @param  func���ص����������ڲ�������
* @retval void * ���ҵ�������
* @note   ���ҵ�ԭ������һ���ؼ���keyWord��������ؼ��ʴ���ص�����func��
*         �ص������д���ùؼ��������������Ȼ�󷵻ؽ�������ݻص������Ľ����
*         �õ��ڵ��е�����
*/
void *nodeFind(LinkedList *list, const void *keyWord, int(*func)(const void*, const void *));
/**
* @brief  ��������ɾ��һ���ڵ�,������ɾ���ڵ��е����ݡ��������Ϊ��ȡһ������
*
* @param  LinkedList *listҪ����������
* @param  void *keyWord���ؼ��ʣ����ڲ��������е�����
* @param  func���ص����������ڲ�������
* @param  void *backData��ɾ���Ľڵ��е�����
* @retval �����Ľ�����ɹ�����0��ʧ�ܷ���-1
* @note   ɾ��һ���ڵ㣬��ɾ��������ڵ��е����ݴ���backData�У�����ͨ
*         ��backData֪����ɾ�������ݡ�
*         
*/
int nodeFetch(LinkedList *list, const void *keyWord, int(*func)(const void*, const void *),void *backData);
/**
* @brief  ���������е�Ԫ��
*
* @param  LinkedList *listҪ����������
* @param  func���ص����������ڸ���������ָ�������ķ�ʽ
* @retval None
*/
void travelLinkedList(LinkedList *list,void (*func)(const void*));
/**
* @brief  ��������ɾ��һ���ڵ�,��������ɾ���ڵ��е�����
*
* @param  LinkedList *listҪ����������
* @param  void *keyWord���ؼ��ʣ����ڲ��������е�����
* @param  func���ص����������ڲ�������
* @retval int ����������ɹ�����0��ʧ�ܷ���-1
* @note   ɾ����ԭ������һ���ؼ���keyWord��������ؼ��ʴ���ص�����func��
*         �ص������д���ùؼ�����������������ؽ�������ݻص������Ľ����
*         ȷ��ɾ���ĸ��ڵ�
*/
int nodeDelete(LinkedList *list,const void *keyWord,int (*func)(const void*,const void *));
