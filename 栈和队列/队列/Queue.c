#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct Queue
{
	int data;
	struct Queue* pNext;
}queue;
queue* CreateNode(int value)
{
	queue* newNode = (queue*)malloc(sizeof(queue));
	newNode->data = value;
	newNode->pNext = NULL;
	return newNode;
}
void queuePush(queue** qp, int value)
{
	assert(qp);
	//创造新的节点
	queue* newNode = CreateNode(value);
	queue* tail = *qp;
	
	//首节点
	if ((*qp) == NULL)
	{
		(*qp)= newNode;
		return;
	}
	while (tail->pNext != NULL)
	{
		tail = tail->pNext;
	}
	tail->pNext = newNode;
}
void queuePrint(queue** qp)
{
	assert(qp);
	assert((*qp)!=NULL);
	queue* tail = *qp;
	while (tail)
	{
		printf("%d ", tail->data);
		tail = tail->pNext;
	}
	printf("\n");
}
void queuePop(queue** qp)
{
	assert(qp);
	*qp = (*qp)->pNext;
}
void queueFront(queue** qp)
{
	printf("queueFront=%d\n", (*qp)->data);
}
void queueBack(queue** qp)
{
	assert(qp);
	queue* tail = *qp;
	while (tail->pNext)
	{
		tail = tail->pNext;
	}
	printf("queueBack=%d\n", tail->data);
}
void queueSum(queue** qp)
{
	assert(qp);
	int sum = 0;
	queue* tail = *qp;
	while (tail)
	{
		sum++;
		tail = tail->pNext;
	}
	printf("queueSum=%d\n", sum);
}
int queueIsEmpty(queue** qp)
{
	assert(qp);
	if ((*qp) == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void queueDestroy(queue** qp)
{
	assert(qp);
	while (*qp)
	{
		queue* Next = (*qp)->pNext;
		free(*qp);
		*qp = NULL;
		*qp = Next;
	}
}
int main()
{
	queue* q = NULL;

	//入队列
	queuePush(&q, 1);
	queuePush(&q, 2);
	queuePush(&q, 3);
	queuePush(&q, 4);
	queuePush(&q, 5);
	queuePush(&q, 6);
	queuePush(&q, 7);
	queuePush(&q, 8);

	//出队列
	queuePop(&q);

	//打印队列
	queuePrint(&q);

	//获取队列头部数据
	queueFront(&q);

	//获取队列尾部数据
	queueBack(&q);

	//获取队列当中有效元素的个数
	queueSum(&q);

	//检测队列是否为空
	int cnt = queueIsEmpty(&q);
	if (0 == cnt)
	{
		printf("不是空队列\n");
	}
	else
	{
		printf("空队列\n");
	}

	//队列销毁
	queueDestroy(&q);

	return 0;
}