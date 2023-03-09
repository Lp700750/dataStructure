//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<stdlib.h>
//typedef struct InsertSort
//{
//	int capacity;
//	int size;
//	int* head;
//}InsertSort;
//void InsertSortInit(InsertSort* pis)
//{
//	pis->capacity = pis->size = 0;
//	pis->head = NULL;
//}
//void addSpace(InsertSort* pis)
//{
//	int newCapacity = pis->capacity == 0 ? 5 : 2 * pis->capacity;
//	int* newSpace = (int*)realloc(pis->head, newCapacity * sizeof(int));
//	pis->capacity = newCapacity;
//	pis->head = newSpace;
//}
//void insertData(InsertSort* pis, int value)
//{
//	//���ռ��Ƿ���
//	if (pis->capacity == pis->size)
//	{
//		//����
//		addSpace(pis);
//	}
//	pis->head[pis->size++] = value;
//}
//void Print(InsertSort* pis)
//{
//	for (int i = 0; i < pis->size; i++)
//	{
//		printf("%d ", pis->head[i]);
//	}
//	printf("\n");
//}
//void swap(int* front, int* back)
//{
//	int temp = *front;
//	*front = *back;
//	*back = temp;
//}
//void dataSort(InsertSort* pis)
//{
//	//1.����
//	//2.������
//}
//void destroySort(InsertSort* pis)
//{
//	free(pis->head);
//	pis->head = NULL;
//}
//void adjustUp(InsertSort* pis)
//{
//	int child = pis->size - 1;
//	int parent = (child - 1) / 2;
//	while (parent>=0)
//	{
//		if (pis->head[child] > pis->head[parent])
//		{
//			swap(&pis->head[child], &pis->head[parent]);
//			child = parent;
//			parent = (child - 1) / 2;
//		}
//		else
//		{
//			break;
//		}
//	}
//
//}
//void heapInsert(InsertSort* pis, int value)
//{
//	//���ռ��Ƿ���
//	if (pis->capacity == pis->size)
//	{
//		//����
//		addSpace(pis);
//	}
//	pis->head[pis->size++] = value;
//	adjustUp(pis);
//}
//void adjustDown(InsertSort* pis, int child)
//{
//	for (int i = child; i > 0; i--)
//	{
//		child = i;
//		int parent = (child - 1) / 2;
//		int size = child;
//		while (child <= size)
//		{
//			if (child + 1 < size&&pis->head[child] < pis->head[child + 1])
//			{
//				child = child + 1;
//			}
//			if (pis->head[parent] < pis->head[child])
//			{
//				swap(&pis->head[parent], &pis->head[child]);
//				child = parent;
//				parent = (child - 1) / 2;
//			}
//			else
//			{
//				break;
//			}
//		}
//	}
//}
//void Sort(InsertSort* pis)
//{
//	int end = pis->size - 1;
//	while (end)
//	{
//		swap(&pis->head[0], &pis->head[end]);
//		end--;
//		adjustDown(pis, end);
//	}
//}
//int main()
//{
//	//�������������
//	InsertSort is;
//	InsertSortInit(&is);
//
//
//	//������Ե�����
//	int testData[10] = { 8,5,4,2,6,9,3,7,1,10 };
//
//	//������������
//	for (int i = 0; i < 10; i++)
//	{
//		//insertData(&is, testData[i]);
//		//����
//		heapInsert(&is,testData[i]);
//	}
//	//����
//	Sort(&is);
//	Print(&is);
//
//	//������
//	//dataSort(&is);
//	//Print(&is);
//
//	//��������
//	destroySort(&is);
//
//	return 0;
//}