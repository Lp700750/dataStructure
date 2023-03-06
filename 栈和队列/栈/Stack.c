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
	
	//申请空间
	CreateNode(pHead);
}
void StackPush(Stack* pHead, int value)
{
	if (pHead->capacity == pHead->size)
	{
		//扩容
		CreateNode(pHead);
	}
	pHead->Head[pHead->size++] = value;
}
void StackPop(Stack* pHead)
{
	if (0 == pHead->size)
	{
		printf("空栈\n");
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
		printf("空栈\n");
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

	//初始化栈结构
	StackInit(&s);

	//入栈
	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);
	StackPush(&s, 6);
	StackPush(&s, 7);
	StackPush(&s, 8);

	//出栈
	StackPop(&s);

	//获取栈顶元素
	int ret = StackFront(&s);

	//获取栈内有效数据个数
	StackSum(&s);

	//检测栈是否为空
	int cnt = StackIsEmpty(&s);
	if (0 == cnt)
	{
		printf("不为空栈\n");
	}
	else
	{
		printf("空栈\n");
	}

	//打印栈
	StackPrint(&s);

	//销毁栈
	StackDestroy(&s);
}