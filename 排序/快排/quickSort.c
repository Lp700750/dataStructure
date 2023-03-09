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
int _dataSort(InsertSort* pis, int left, int right)
{
	int keyi = left;
	while (left < right)
	{
		while (left < right&&pis->head[right] >= pis->head[keyi])
		{
			right--;
		}
		while (left < right&&pis->head[keyi] >= pis->head[left])
		{
			left++;
		}
		swap(&pis->head[left], &pis->head[right]);
	}
	swap(&pis->head[left], &pis->head[keyi]);
	return left;
}
int getMidIndex(InsertSort* pis, int left, int right)
{
	int midi = left + (right - left) / 2;
	if (pis->head[left] < pis->head[midi])
	{
		if (pis->head[midi] < pis->head[right])
		{
			return midi;
		}
		else if (pis->head[left] < pis->head[right])
		{
			return right;
		}
		else
		{
			return left;
		}
	}
	else
	{
		if (pis->head[midi] > pis->head[right])
		{
			return midi;
		}
		else if (pis->head[left] > pis->head[right])
		{
			return right;
		}
		else
		{
			return left;
		}
	}
}
void dataSort(InsertSort* pis,int left,int right)
{
	//left = 0;
	//right = pis->size - 1;
	if (left >= right)
	{
		return;
	}
	int midi = getMidIndex(pis, left, right);
	swap(&pis->head[midi], &pis->head[left]);

	int keyi = _dataSort(pis, left, right);

	dataSort(pis, left, keyi - 1);
	dataSort(pis, keyi+1, right);
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

	//直接插入排序
	int size = sizeof(testData) / sizeof(int);
	dataSort(&is,0,size-1);
	Print(&is);

	//销毁容器
	destroySort(&is);

	return 0;
}