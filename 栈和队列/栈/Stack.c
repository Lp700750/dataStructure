#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Stack
{
	int capacity;
	int size;
	int* Head;
}Stack;
void CreateNode(Stack* pHead)
{
	int newCapacity = pHead->capacity == 0 ? 5 : 2 * pHead->capacity;
	int* newHead = (int*)realloc(pHead->Head, sizeof(int)*newCapacity);
	pHead->capacity = newCapacity;
	pHead->Head = newHead;
}
void StackInit(Stack* pHead)
{
	pHead->capacity = 0;
	pHead->size = 0;
	pHead->Head = NULL;
	
	//����ռ�
	CreateNode(pHead);
}
void StackPush(Stack* pHead, int value)
{
	if (pHead->capacity == pHead->size)
	{
		//����
		CreateNode(pHead);
	}
	pHead->Head[pHead->size++] = value;
}
void StackPop(Stack* pHead)
{
	if (0 == pHead->size)
	{
		printf("��ջ\n");
		exit(1);
	}
	pHead->size--;
}
void StackPrint(Stack* pHead)
{
	for (int i = 0; i < pHead->size; i++)
	{
		printf("%d ", pHead->Head[i]);
	}
}
int StackFront(Stack* pHead)
{
	if (0 == pHead->size)
	{
		printf("��ջ\n");
		exit(1);
	}
	return pHead->Head[pHead->size];
}
void StackSum(Stack* pHead)
{
	printf("stackNum=%d\n", pHead->size);
}
int StackIsEmpty(Stack* pHead)
{
	if (0==pHead->size)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}
void StackDestroy(Stack* pHead)
{
	free(pHead->Head);
	pHead->Head = NULL;
}
int main()
{
	Stack s;

	//��ʼ��ջ�ṹ
	StackInit(&s);

	//��ջ
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);
	StackPush(&s, 6);
	StackPush(&s, 7);
	StackPush(&s, 8);

	//��ջ
	StackPop(&s);

	//��ȡջ��Ԫ��
	int ret = StackFront(&s);

	//��ȡջ����Ч���ݸ���
	StackSum(&s);

	//���ջ�Ƿ�Ϊ��
	int cnt = StackIsEmpty(&s);
	if (0 == cnt)
	{
		printf("��Ϊ��ջ\n");
	}
	else
	{
		printf("��ջ\n");
	}

	//��ӡջ
	StackPrint(&s);

	//����ջ
	StackDestroy(&s);
}