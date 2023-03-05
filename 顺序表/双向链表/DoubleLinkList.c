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
		printf("����Ϊ�� ���ܹ�����ɾ��\n");
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
	printf("�����в����ڸ�ֵ\n");
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
	//��ʼ��ͷ�ڵ�
	DList* pHead = HeadNodeInit();

	//�������ӽڵ�
	DListInsert(&pHead, 1);
	DListInsert(&pHead, 2);
	DListInsert(&pHead, 3);
	DListInsert(&pHead, 4);
	DListInsert(&pHead, 5);
	DListInsert(&pHead, 6);
	DListInsert(&pHead, 7);
	DListInsert(&pHead, 8);

	//����ɾ���ڵ�
	DListErase(&pHead);

	//������ҽڵ�
	DList*Node = DlistFind(&pHead, 5);

	//�����޸Ľڵ�
	DlistModify(&pHead, Node, 15);

	//�����ӡ
	DListPrint(&pHead);

	//�����ͷ�
	DListDestroy(&pHead);

	return 0;
}