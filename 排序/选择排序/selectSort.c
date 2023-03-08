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
	//int end = pis->size;
	//int maxi = end-1;
	//while (maxi > 0)
	//{
	//	for (int i = 0; i < maxi+1; i++)
	//	{
	//		if (pis->head[maxi] < pis->head[i])
	//		{
	//			swap(&pis->head[maxi], &pis->head[i]);
	//		}
	//	}
	//	maxi--;
	//}

	int end = pis->size - 1;
	while (end)
	{
		int maxi = end;
		//找出这一轮里面最大的那个值的位置
		for (int i = 0; i < end; i++)
		{
			if (pis->head[i] > pis->head[maxi])
			{
				maxi = i;
			}
		}
		//将最大值与该列数据的最后一个相换，保证最大值在后面
		swap(&pis->head[maxi], &pis->head[end]);
		end--;
	}
}
void dataSortPlus(InsertSort* pis)
{
	int start = 0;
	int end = pis->size - 1;
	while (start < end)
	{
		int maxi = end;
		int mini = start;
		for (int i = start; i < end; i++)
		{
			if (pis->head[i] > pis->head[maxi])
			{
				maxi = i;
			}
			if (pis->head[i] < pis->head[mini])
			{
				mini = i;
			}
		}
		swap(&pis->head[end], &pis->head[maxi]);
		if (start == maxi)
		{
			maxi = mini;
		}
		swap(&pis->head[start], &pis->head[mini]);
		start++;
		end--;
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

	//选择排序
	//dataSort(&is);
	dataSortPlus(&is);
	Print(&is);

	//销毁容器
	destroySort(&is);

	return 0;
}