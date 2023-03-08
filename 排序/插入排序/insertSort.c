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
	//���ռ��Ƿ���
	if (pis->capacity == pis->size)
	{
		//����
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
	for (int i = 0; i < pis->size-1; i++)
	{
		while (i >= 0)
		{
			if (pis->head[i] > pis->head[i + 1])
			{
				swap(&pis->head[i], &pis->head[i + 1]);
				i--;
			}
			else
			{
				break;
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
	//�������������
	InsertSort is;
	InsertSortInit(&is);


	//������Ե�����
	int testData[10] = { 8,5,4,2,6,9,3,7,1,10 };

	//������������
	for (int i = 0; i < 10; i++)
	{
		insertData(&is, testData[i]);
	}
	Print(&is);

	//ֱ�Ӳ�������
	dataSort(&is);
	Print(&is);

	//��������
	destroySort(&is);

	return 0;
}