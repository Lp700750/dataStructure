#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
//������ͷ����
typedef struct ListNode
{
	int data;
	struct ListNode* pNext;
}List;
List* CreateNode(int value)
{
	List* newNode = (List*)malloc(sizeof(List));
	newNode->data = value;
	newNode->pNext = NULL;

	return newNode;
}
void ListInsert(List** pplist, int value)
{
	//�����µĽڵ�
	assert(pplist);
	List* newNode = CreateNode(value);

	//��Ϊͷ�ڵ�
	if (*pplist == NULL)
	{
		*pplist = newNode;
	}
	//��Ϊβ�ڵ�
	else
	{
		List* tail = *pplist;
		while (tail->pNext)
		{
			tail = tail->pNext;
		}
		tail->pNext = newNode;
	}
}
void ListErase(List** pplist)
{
	assert(pplist);
	if (*pplist == NULL)
	{
		printf("�������ܹ�����ɾ��\n");
		exit(1);
	}
	List* tail = *pplist;
	//�����ڵ�
	if (tail->pNext == NULL)
	{
		free(tail);
		tail = NULL;
	}
	//����ڵ�
	else
	{
		while (tail->pNext->pNext)
		{
			tail = tail->pNext;
		}
		free(tail->pNext);
		tail->pNext = NULL;
	}
}
List* ListFind(List** pplist, int value)
{
	assert(pplist);
	List* tail = *pplist;
	while (tail)
	{
		if (tail->data == value)
		{
			return tail;
		}
		tail = tail->pNext;
	}
	return NULL;
}
void ListModify(List** pplist,List* pNode,int value)
{
	assert(pplist);
	List* _pNode = *pplist;
	while (_pNode)
	{
		if (_pNode == pNode)
		{
			_pNode->data = value;
			return;
		}
		_pNode = _pNode->pNext;
	}
}
void ListPrint(List** pplist)
{
	assert(pplist);
	List* tail = *pplist;
	while (tail)
	{
		printf("%d ", tail->data);
		tail = tail->pNext;
	}
}
void ListDestroy(List** pplist)
{
	assert(pplist);
	List* current = *pplist;
	while (current)
	{
		List* Next = current->pNext;
		free(current);
		current = NULL;
		current = Next;
	}
}
int main()
{
	List* plist=NULL;
	

	//���ӽڵ�
	ListInsert(&plist, 1);
	ListInsert(&plist, 2);
	ListInsert(&plist, 3);
	ListInsert(&plist, 4);
	ListInsert(&plist, 5);
	ListInsert(&plist, 6);
	ListInsert(&plist, 7);
	ListInsert(&plist, 8);

	//ɾ���ڵ�
	ListErase(&plist);

	//���ҽ��
	List* pNode = ListFind(&plist, 5);

	//�޸Ľڵ�
	ListModify(&plist,pNode,15);

	//��ӡ�ڵ�
	ListPrint(&plist);

	//�ͷ�����
	ListDestroy(&plist);

	return 0;
}