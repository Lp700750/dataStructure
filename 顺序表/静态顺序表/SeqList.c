#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define NUM 10
typedef struct SeqList
{
	//����ĳ���
	int arr[NUM];
	//��ǰ����Ĵ�С
	int size;
}SeqList;
void SeqListInit(SeqList* sl)
{
	memset(sl->arr, 0, NUM*sizeof(int));
	sl->size = 0;
}
void SeqListPush(SeqList* sl ,int value)
{
	if (NUM == sl->size)
	{
		printf("�ռ�����\n");
		exit(1);
	}
	sl->arr[sl->size] = value;
	sl->size++;
}
void SeqListErase(SeqList* sl)
{
	if (0 == sl->size)
	{
		printf("û�п���ɾ��������\n");
		exit(2);
	}
	sl->size--;
}
int* SeqListFind(SeqList* sl, int value)
{
	for (int i = 0; i < (sl->size); i++)
	{
		if (sl->arr[i] == value)
		{
			return &(sl->arr[i]);
		}
	}
		printf("û���ҵ�\n");
		return NULL;

}
void SeqListModify(int value ,int* Sp)
{
	(*Sp) = value;
}
void print(SeqList* sl)
{
	for (int i = 0; i < (sl->size); i++)
	{
		printf("%d ", sl->arr[i]);
	}
}
int main()
{
	SeqList sl;

	//˳���ĳ�ʼ��
	SeqListInit(&sl);

	//˳�����������
	SeqListPush(&sl, 1);
	SeqListPush(&sl, 2);
	SeqListPush(&sl, 3);
	SeqListPush(&sl, 4);
	SeqListPush(&sl, 5);
	SeqListPush(&sl, 6);
	SeqListPush(&sl, 7);
	SeqListPush(&sl, 8);
	SeqListPush(&sl, 9);
	SeqListPush(&sl, 10);

	//˳���ɾ������
	SeqListErase(&sl);
	SeqListPush(&sl, 12);

	//˳����������
	int* Sp = SeqListFind(&sl, 5);

	//˳����޸�����
	SeqListModify(15,Sp);

	//��ӡ����
	print(&sl);
 }