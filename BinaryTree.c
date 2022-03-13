#include <stdio.h>
#include <stdlib.h>

typedef int Data;

typedef struct _node {
	Data data;
	struct _node* left;
	struct _node* right;
}Node;

Node* MakeTreeNode(void)
{
	// Node 하나를 만들면 "공집합" 자식 노드 2개가 자동으로 생성된다. 그것 또한 이진트리임. 
	Node* nd = (Node*)malloc(sizeof(Node));
	nd->left = NULL;
	nd->right = NULL;
	return nd;
}

Data GetData(Node* bt)
{
	return bt->data;
} 

void SetData(Node* bt, Data data)
{
	bt->data = data;
}

Node* GetLeftSubTree(Node* bt)
{
	return bt->left;
}

Node* GetRightSubTree(Node* bt)
{
	return bt->right;
}

void MakeLeftSubTree(Node* main, Node* sub)
{
	// 만약 이미 왼쪽 자식이 존재한다면, 삭제하고 새로운 자식을 추가한다.
	// 현재 코드로 트리의  '순회'는 하지 못한다. 
	if ( main->left != NULL )
	{
		free(main->left);
	} 
	
	main->left = sub;
}

void MakeRightSubTree(Node* main, Node* sub)
{
	if ( main->right != NULL )
	{
		free(main->right);
	} 
	
	main->right = sub;
}

void InorderTraverse(Node* bt)
{
	if ( bt == NULL )
	{
		return;
	}
	InorderTraverse(bt->left);
	printf("%d\n", bt->data);
	InorderTraverse(bt->right);
} 

void DeleteTree(Node* bt)
{
	if ( bt == NULL )
	{
		return;
	}
	
	DeleteTree(bt->left);
	DeleteTree(bt->right);
	printf("del tree data: %d\n", bt->data);
	free(bt);
}

int main(void)
{
	Node* bt1 = MakeTreeNode();
	Node* bt2 = MakeTreeNode();
	Node* bt3 = MakeTreeNode();
	Node* bt4 = MakeTreeNode();
	
	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);
	
	MakeLeftSubTree(bt1, bt2);
	MakeRightSubTree(bt1, bt3);
	MakeLeftSubTree(bt2, bt4);
	
//	printf("%d\n", GetData(GetLeftSubTree(bt1)));
	
//	printf("%d\n", GetData(GetLeftSubTree(GetLeftSubTree(bt1))));
	
	InorderTraverse(bt1);
	
	printf("\n");
	
	DeleteTree(bt1);
	
	return 0;
}
