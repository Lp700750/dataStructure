#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//��װ����
typedef struct DSeqList
{
	int* arry;
	size_t size;
	size_t capacity;
}DSeqList;
//����
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
	//�ɰ汾
	//dsl->arry = (int*)malloc(5 * sizeof(int));

	//�°汾
	Dilatation(dsl);
}
void DSeqListPush(DSeqList* dsl, int value)
{
	//����ռ䲻���Ļ�������Ҫ����
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
		printf("�ռ䲻��\n");
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
	printf("δ�ҵ�\n");
	return -1;
}
void DSeqListErase(DSeqList* dsl, int value)
{
	if (dsl->size == 0)
	{
		printf("�ռ䲻��\n");
		return;
	}
	int size = DSeqListFind(dsl, value);
	if (-1 == size)
	{
		printf("�Ҳ�����Ӧ�����ݣ��޷�����ɾ��\n");
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

	//��ʼ����̬˳���
	DSeqListInit(&dsl);

	//��̬˳����������
	DSeqListPush(&dsl, 1);
	DSeqListPush(&dsl, 2);
	DSeqListPush(&dsl, 3);
	DSeqListPush(&dsl, 4);
	DSeqListPush(&dsl, 5);
	DSeqListPush(&dsl, 6);
	DSeqListPush(&dsl, 7);
	DSeqListPush(&dsl, 8);

	//��̬˳���ɾ������
	DSeqListPop(&dsl);
	
	//��̬˳����������
	int _size = DSeqListFind(&dsl, 5);
	DSeqListErase(&dsl, 5);

	//��̬˳����޸�����
	_size = DSeqListFind(&dsl, 2);
	DSeqListModify(&dsl,_size, 15);

	//��ӡ��̬˳���
	DSeqListPrint(&dsl);

	//˳����ɾ��
	DSeqListDestroy(&dsl);

	return 0;
}