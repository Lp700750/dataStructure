#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
//单向无头链表
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
	//构建新的节点
	assert(pplist);
	List* newNode = CreateNode(value);

	//作为头节点
	if (*pplist == NULL)
	{
		*pplist = newNode;
	}
	//作为尾节点
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
		printf("空链表不能够进行删除\n");
		exit(1);
	}
	List* tail = *pplist;
	//单个节点
	if (tail->pNext == NULL)
	{
		free(tail);
		tail = NULL;
	}
	//多个节点
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
	

	//增加节点
	ListInsert(&plist, 1);
	ListInsert(&plist, 2);
	ListInsert(&plist, 3);
	ListInsert(&plist, 4);
	ListInsert(&plist, 5);
	ListInsert(&plist, 6);
	ListInsert(&plist, 7);
	ListInsert(&plist, 8);

	//删除节点
	ListErase(&plist);

	//查找结点
	List* pNode = ListFind(&plist, 5);

	//修改节点
	ListModify(&plist,pNode,15);

	//打印节点
	ListPrint(&plist);

	//释放链表
	ListDestroy(&plist);

	return 0;
}