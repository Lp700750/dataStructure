#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//包装容器
typedef struct DSeqList
{
	int* arry;
	size_t size;
	size_t capacity;
}DSeqList;
//扩容
void Dilatation(DSeqList* dsl)
{
	int newCapacity = dsl->capacity == 0 ? 5 : 2 * (dsl->capacity);
	int* newArry = (int*)realloc(dsl->arry, newCapacity * sizeof(int));
	dsl->arry = newArry;
	dsl->capacity = newCapacity;
}
void DSeqListInit(DSeqList* dsl)
{
	dsl->capacity = 0;
	dsl->size = 0;
	dsl->arry = NULL;
	//旧版本
	//dsl->arry = (int*)malloc(5 * sizeof(int));

	//新版本
	Dilatation(dsl);
}
void DSeqListPush(DSeqList* dsl, int value)
{
	//如果空间不够的话，就需要扩容
	if (dsl->size == dsl->capacity)
	{
		Dilatation(dsl);
	}

	dsl->arry[dsl->size] = value;
	dsl->size++;
}
void DSeqListPop(DSeqList* dsl)
{
	if (dsl->size == 0)
	{
		printf("空间不够\n");
		return;
	}
	dsl->size--;
}
int DSeqListFind(DSeqList* dsl, int value)
{
	for (int i = 0; i < (dsl->size); i++)
	{
		if (value == dsl->arry[i])
		{
			return i;
		}
	}
	printf("未找到\n");
	return -1;
}
void DSeqListErase(DSeqList* dsl, int value)
{
	if (dsl->size == 0)
	{
		printf("空间不够\n");
		return;
	}
	int size = DSeqListFind(dsl, value);
	if (-1 == size)
	{
		printf("找不到相应的数据，无法进行删除\n");
		return;
	}
	for (int i = size; i < dsl->size-1 ; i++)
	{
		dsl->arry[i] = dsl->arry[i + 1];
	}
	dsl->size--;
}
void DSeqListModify(DSeqList* dsl, int _size, int value)
{
	dsl->arry[_size] = value;
}
void DSeqListPrint(DSeqList* dsl)
{
	for (int i = 0; i < dsl->size; i++)
	{
		printf("%d ", dsl->arry[i]);
	}
}
void DSeqListDestroy(DSeqList* dsl)
{
	free(dsl->arry);
	dsl->arry = NULL;
}
int main()
{
	DSeqList dsl;

	//初始化动态顺序表
	DSeqListInit(&dsl);

	//动态顺序表插入数据
	DSeqListPush(&dsl, 1);
	DSeqListPush(&dsl, 2);
	DSeqListPush(&dsl, 3);
	DSeqListPush(&dsl, 4);
	DSeqListPush(&dsl, 5);
	DSeqListPush(&dsl, 6);
	DSeqListPush(&dsl, 7);
	DSeqListPush(&dsl, 8);

	//动态顺序表删除数据
	DSeqListPop(&dsl);
	
	//动态顺序表查找数据
	int _size = DSeqListFind(&dsl, 5);
	DSeqListErase(&dsl, 5);

	//动态顺序表修改数据
	_size = DSeqListFind(&dsl, 2);
	DSeqListModify(&dsl,_size, 15);

	//打印动态顺序表
	DSeqListPrint(&dsl);

	//顺序表的删除
	DSeqListDestroy(&dsl);

	return 0;
}