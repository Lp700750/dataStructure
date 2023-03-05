#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct DoubleLinkList
{
	int data;
	struct DoubleLinkList* pNext;
	struct DoubleLinkList* pLast;
}DList;
DList* HeadNodeInit()
{
	DList* Head = (DList*)malloc(sizeof(DList));
	Head->pLast = Head;
	Head->pNext = Head;
	
	return Head;
}
DList* CreateNode(int value)
{
	DList* newNode = (DList*)malloc(sizeof(DList));
	newNode->data = value;
	newNode->pLast = NULL;
	newNode->pNext = NULL;

	return newNode;
}
void DListInsert(DList** pdlist, int value)
{
	assert(pdlist);
	DList* newNode = CreateNode(value);
	DList* current = *pdlist;
	while (current->pNext != *pdlist)
	{
		current = current->pNext;
	}
	current->pNext = newNode;
	newNode->pLast = current;
	newNode->pNext = *pdlist;
	(*pdlist)->pLast = newNode;
}
void DListErase(DList** pdlist)
{
	assert(pdlist);
	DList* current = *pdlist;
	if ((*pdlist)->pNext == (*pdlist))
	{
		printf("链表为空 不能够进行删除\n");
		exit(1);
	}
	while (current->pNext != *pdlist)
	{
		current = current->pNext;
	}
	current->pLast->pNext = (*pdlist);
	(*pdlist)->pLast = current->pLast;
}
void DListPrint(DList** pdlist)
{
	assert(pdlist);
	assert((*pdlist)->pNext != *pdlist);
	DList* current = (*pdlist)->pNext;
	while (current != *pdlist)
	{
		printf("%d ", current->data);
		current = current->pNext;
	}
}
DList* DlistFind(DList** pdlist, int value)
{
	assert(pdlist);
	assert((*pdlist)->pNext != *pdlist);
	DList* current = (*pdlist)->pNext;
	while (current != *pdlist)
	{
		if (current->data == value)
		{
			return current;
		}
		current = current->pNext;
	}
	printf("链表当中不存在该值\n");
	return NULL;
}
void DlistModify(DList** pdlist, DList* Node, int value)
{
	assert(pdlist);
	assert((*pdlist)->pNext != *pdlist);
	DList* current = (*pdlist)->pNext;
	while (current != *pdlist)
	{
		if (current == Node)
		{
			current->data = value;
			return;
		}
		current = current->pNext;
	}
}
void DListDestroy(DList** pdlist)
{
	assert(pdlist);
	assert((*pdlist)->pNext != *pdlist);
	DList* current = (*pdlist)->pNext;
	while (current != *pdlist)
	{
		DList*Next = current->pNext;
		free(current);
		current = NULL;
		current = Next;
	}
	free(*pdlist);
	(*pdlist) = NULL;
}
int main()
{
	//初始化头节点
	DList* pHead = HeadNodeInit();

	//链表增加节点
	DListInsert(&pHead, 1);
	DListInsert(&pHead, 2);
	DListInsert(&pHead, 3);
	DListInsert(&pHead, 4);
	DListInsert(&pHead, 5);
	DListInsert(&pHead, 6);
	DListInsert(&pHead, 7);
	DListInsert(&pHead, 8);

	//链表删除节点
	DListErase(&pHead);

	//链表查找节点
	DList*Node = DlistFind(&pHead, 5);

	//链表修改节点
	DlistModify(&pHead, Node, 15);

	//链表打印
	DListPrint(&pHead);

	//链表释放
	DListDestroy(&pHead);

	return 0;
}