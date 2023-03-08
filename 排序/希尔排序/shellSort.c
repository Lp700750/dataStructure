#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef struct InsertSort
{
	int capacity;
	int size;
	int* head;
}InsertSort;
void InsertSortInit(InsertSort* pis)
{
	pis->capacity = pis->size = 0;
	pis->head = NULL;
}
void addSpace(InsertSort* pis)
{
	int newCapacity = pis->capacity == 0 ? 5 : 2 * pis->capacity;
	int* newSpace = (int*)realloc(pis->head, newCapacity * sizeof(int));
	pis->capacity = newCapacity;
	pis->head = newSpace;
}
void insertData(InsertSort* pis, int value)
{
	//检查空间是否够用
	if (pis->capacity == pis->size)
	{
		//扩容
		addSpace(pis);
	}
	pis->head[pis->size++] = value;
}
void Print(InsertSort* pis)
{
	for (int i = 0; i < pis->size; i++)
	{
		printf("%d ", pis->head[i]);
	}
	printf("\n");
}
void swap(int* front, int* back)
{
	int temp = *front;
	*front = *back;
	*back = temp;
}
void dataSort(InsertSort* pis)
{
	int gap = pis->size;
	while (gap > 1)
	{
		//设置间隔数
		gap = gap / 2;
		for (int i = 0; i < gap; i++)
		{
			//进行直接插入的环节
			for (int j = i; j < pis->size-gap; j += gap)
			{
				//防止j被污染
				int end = j;
				while (end >= 0)
				{
					if (pis->head[end] > pis->head[end + gap])
					{
						swap(&pis->head[end], &pis->head[end + gap]);
						end -= gap;
					}
					else
					{
						break;
					}
				}
				
			}
		}

	}
}
void destroySort(InsertSort* pis)
{
	free(pis->head);
	pis->head = NULL;
}
int main()
{
	//定义排序的容器
	InsertSort is;
	InsertSortInit(&is);


	//定义测试的数组
	int testData[10] = { 8,5,4,2,6,9,3,7,1,10 };

	//插入所有数据
	for (int i = 0; i < 10; i++)
	{
		insertData(&is, testData[i]);
	}
	Print(&is);

	//希尔排序
	dataSort(&is);
	Print(&is);

	//销毁容器
	destroySort(&is);

	return 0;
}