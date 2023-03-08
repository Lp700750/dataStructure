#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef struct binaryTreeNode
{
	int data;
	struct binaryTreeNode* liftNode;
	struct binaryTreeNode* rightNode;
}BTNode;
BTNode* newBTNode(int value)
{
	BTNode* newNode = (BTNode*)malloc(sizeof(BTNode));
	newNode->data = value;
	newNode->liftNode = newNode->rightNode = NULL;
	return newNode;
}
void Preorder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%d ", root->data);
	Preorder(root->liftNode);
	Preorder(root->rightNode);
}
void Midorder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	Midorder(root->liftNode);
	printf("%d ", root->data);
	Midorder(root->rightNode);
}
void Posorder(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	Posorder(root->liftNode);
	Posorder(root->rightNode);
	printf("%d ", root->data);
}
int BTreeSize(BTNode* root)
{
	return root == NULL ? 0 : BTreeSize(root->liftNode) + BTreeSize(root->rightNode) + 1;
}
int LeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->liftNode == NULL && root->rightNode == NULL)
	{
		return 1;
	}
	return LeafSize(root->liftNode) + LeafSize(root->rightNode);
}
int DepthTree(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	int LiftDepth = DepthTree(root->liftNode);
	int RightDepth = DepthTree(root->rightNode);

	return LiftDepth > RightDepth ? LiftDepth + 1 : RightDepth + 1;
}
void BTreeDestroy(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BTreeDestroy(root->liftNode);
	BTreeDestroy(root->rightNode);
	free(root);
	root = NULL;
}
int main()
{
	//构建二叉树节点
	BTNode* BTNode1 = newBTNode(1);
	BTNode* BTNode2 = newBTNode(2);
	BTNode* BTNode3 = newBTNode(3);
	BTNode* BTNode4 = newBTNode(4);
	BTNode* BTNode5 = newBTNode(5);
	BTNode* BTNode6 = newBTNode(6);
	BTNode* BTNode7 = newBTNode(7);
	BTNode* BTNode8 = newBTNode(8);

	//构建二叉树连接关系
	BTNode1->liftNode = BTNode2;
	BTNode1->rightNode = BTNode3;
	BTNode2->liftNode = BTNode4;
	BTNode2->rightNode = BTNode5;
	BTNode3->rightNode = BTNode6;
	BTNode5->liftNode = BTNode7;
	BTNode5->rightNode = BTNode8;

	//二叉树遍历
	//Preorder(BTNode1);
	//Midorder(BTNode1);
	Posorder(BTNode1);

	//二叉树节点的个数
	printf("\nTreeSize=%d\n", BTreeSize(BTNode1));

	//二叉树叶子节点的个数
	printf("LeafSize=%d\n", LeafSize(BTNode1));

	//二叉树的深度
	printf("DepthTree=%d\n", DepthTree(BTNode1));



	//二叉树销毁
	BTreeDestroy(BTNode1);

	return 0;
}