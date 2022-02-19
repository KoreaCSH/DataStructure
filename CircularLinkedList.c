#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int LData;

typedef struct _node {
	LData data;
	struct _node* next;
}Node;

typedef struct _cll {
	Node* tail;
	Node* cur;
	Node* before;
	int numOfData;
}CList;

typedef CList List;

void ListInit(List* plist)
{
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
}

// tail�� ������ �߰� 
void LInsert(List* plist, LData data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	if (plist->tail == NULL)
	{
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
		plist->tail = newNode;
	}
	(plist->numOfData)++;
}

// head �κп� ������ �߰� 
void LInsertFront(List* plist, LData data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	if (plist->tail == NULL)
	{
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode; 
	}
	(plist->numOfData)++;
}

int LFirst(List* plist, LData* pdata)
{
	if (plist->tail == NULL)
	{
		return FALSE;
	}
	plist->before = plist->tail;
	plist->cur = plist->tail->next;
	
	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List* plist, LData* pdata)
{
	// �������Ḯ��Ʈ�̹Ƿ� ����Ʈ�� ������ ������� �˻��ϴ� �ڵ尡 �������� �ʴ´�. 
	if (plist->tail == NULL)
	{
		return FALSE;
	}
	plist->before = plist->cur;
	plist->cur = plist->cur->next;
	
	*pdata = plist->cur->data;
	return TRUE;
}

LData LRemove(List* plist)
{
	Node* rpos = plist->cur;
	LData rdata = rpos->data;
	
	// ���� ( tail �� ������ ����� cur �� ����ų ��)
	if ( rpos == plist->tail )
	{
		// ����1) ������ ��尡 ����Ʈ�� ������ ����� ��
		if (plist->tail == plist->tail->next)
		{
			plist->tail = NULL;
		} 
		// ����2) ������ ��带 tail �� ����Ű�� ���
		else
		{
			plist->tail = plist->before;
		} 
	}
	
	// �Ϲ����� ���
	plist->before->next = plist->cur->next;
	plist->cur = plist->before;
	
	free(rpos);
	(plist->numOfData)--;
	return rdata; 
}

int LCount(List* plist)
{
	return plist->numOfData;
}

int main(void)
{
	List list;
	int data, i, nodeNum;
	ListInit(&list);
	
	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);
	LInsertFront(&list, 2);
	LInsertFront(&list, 1);
	
	if(LFirst(&list, &data))
	{
		printf("%d ", data);
		
		for ( i = 0 ; i < LCount(&list)*3-1 ; i++ )
		{
			if ( LNext(&list, &data) )
			{
				printf("%d ", data);
			}
		}
	}
	printf("\n");
	
	// 2�� ��� ã�Ƽ� ���� //
	nodeNum = LCount(&list);
	
	if ( nodeNum != 0 )
	{
		LFirst(&list, &data);
		if ( data % 2 == 0 )
		{
			LRemove(&list);
		}
		
		for ( i = 0; i < nodeNum - 1; i++ )
		{
			LNext(&list, &data);
			if ( data % 2 == 0 )
			{
				LRemove(&list);
			}
		}
	}
	
	if (LFirst(&list, &data))
	{
		printf("%d ", data);
		for ( i = 0; i < LCount(&list)-1; i++ )
		{
			if (LNext(&list, &data))
			{
				printf("%d ", data);
			}
		}
	}
	
	return 0;
}
