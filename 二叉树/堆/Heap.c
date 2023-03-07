#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef struct Heap
{
	int size;
	int capacity;
	int* phead;
}Heap;
int* CreateSpace(Heap* p)
{
	int newCapacity = p->capacity == 0 ? 5 : 2 * p->capacity;
	int* newSpace = (int*)realloc(p->phead, sizeof(int)*newCapacity);
	p->capacity = newCapacity;
	return newSpace;
}
void HeapInit(Heap* p)
{
	p->capacity = 0;
	p->size = 0;
	p->phead = NULL;
	
	//��Heap�ռ��������
	p->phead = CreateSpace(p);
}
void swap(int* front, int* back)
{
	int temp = *front;
	*front = *back;
	*back = temp;
}
void adjustDown(Heap* p, int size,int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if ((child + 1) < size&&(p->phead[child + 1] < p->phead[child]))
		{
			child++;
		}
		if (p->phead[child] < p->phead[parent])
		{
			swap(&p->phead[child], &p->phead[parent]);
			parent = child;
			child = 2 * child + 1;
		}
		else
		{
			break; 
		}
	}
}
void heapPrint(Heap* p)
{
	for (int i = 0; i < p->size; i++)
	{
		printf("%d ", p->phead[i]);
	}
	printf("\n");
}
void adjustUp(Heap* p, int child)
{
	int parent = (child - 1) / 2;
	while (child)
	{
		if (p->phead[child] < p->phead[parent])
		{
			swap(&p->phead[child], &p->phead[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}
void heapInsert(Heap* p, int value)
{
	if (p->capacity == p->size)
	{
		//�ռ䲻������Ҫ����
		CreateSpace(p);
	}
	p->phead[p->size++] = value;
	
	//С��
	adjustUp(p, p->size - 1);
}
void heapErase(Heap* p)
{
	swap(&p->phead[0], &p->phead[(p->size) - 1]);
	p->size--;
	adjustDown(p, p->size, 0); 
}
int heapIsEmpty(Heap* p)
{
	return p->size;
}
void heapDestroy(Heap* p)
{
	free(p->phead);
	p->phead = NULL;
}
int main() 
{
	//����Heap����
	int arryTest[10] = { 27,15,19,18,28,34,65,49,25,37};
	//15 18 19 27 28 34 65 49 25 37
	//15 18 19 25 28 34 65 49 27 37
	//27 28 65 49 37 19 34 15 25 18
	//15 18 19 25 28 34 65 49 27 37
	//15 37 19 25 18 34 65 49 27
	//18 25 19 27 28 34 65 49 37

	//��Heap���г�ʼ��
	Heap p;
	HeapInit(&p);

	//�Ѳ���
	for (int i = 0; i < 10; i++)
	{
		heapInsert(&p, arryTest[i]);
	}

	//�Ѵ�ӡ
	heapPrint(&p);

	//��ɾ���Ѷ�����
	heapErase(&p);

	//�Ѵ�ӡ
	heapPrint(&p);

	//���Ƿ�Ϊ��
	int ret = heapIsEmpty(&p);
	if (ret > 0)
	{
		printf("��Ϊ��\n");
	}
	else
	{
		printf("�ն�\n");
	}

	//�ѵ�����
	heapDestroy(&p);

	return 0;
}