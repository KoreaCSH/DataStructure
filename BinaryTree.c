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
	// Node �ϳ��� ����� "������" �ڽ� ��� 2���� �ڵ����� �����ȴ�. �װ� ���� ����Ʈ����. 
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
	// ���� �̹� ���� �ڽ��� �����Ѵٸ�, �����ϰ� ���ο� �ڽ��� �߰��Ѵ�.
	// ���� �ڵ�� Ʈ����  '��ȸ'�� ���� ���Ѵ�. 
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
