#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define NUM 10
typedef struct SeqList
{
	//数组的长度
	int arr[NUM];
	//当前数组的大小
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
		printf("空间已满\n");
		exit(1);
	}
	sl->arr[sl->size] = value;
	sl->size++;
}
void SeqListErase(SeqList* sl)
{
	if (0 == sl->size)
	{
		printf("没有可以删除的数据\n");
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
		printf("没有找到\n");
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

	//顺序表的初始化
	SeqListInit(&sl);

	//顺序表增加数据
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

	//顺序表删除数据
	SeqListErase(&sl);
	SeqListPush(&sl, 12);

	//顺序表查找数据
	int* Sp = SeqListFind(&sl, 5);

	//顺序表修改数据
	SeqListModify(15,Sp);

	//打印数据
	print(&sl);
 }