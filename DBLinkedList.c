#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0 

typedef int LData;

typedef struct _node {
	LData data;
	struct _node* next;
	struct _node* prev;
}Node; 

typedef struct _Dlinkedlist {
	Node* head;
	Node* tail; 
	Node* cur;
	int numOfData;
}DBLinkedList;

typedef DBLinkedList List;

void ListInit(List* plist)
{
	plist->head = (Node*)malloc(sizeof(Node));
	plist->tail = (Node*)malloc(sizeof(Node));
	
	plist->head->next = plist->tail;
	plist->head->prev = NULL;
	
	plist->tail->next = NULL;
	plist->tail->prev = plist->head;
	
	plist->numOfData = 0;
}

void LInsert(List* plist, LData data)
{
	// 그림 그리면서 복습하자 ! 
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	newNode->prev = plist->tail->prev;
	plist->tail->prev->next = newNode;
	
	newNode->next = plist->tail;
	plist->tail->prev = newNode;
	
	(plist->numOfData)++;
}

int LFirst(List* plist, LData* data)
{
	if (plist->head->next == plist->tail)
	{
		return FALSE;
	}
	
	plist->cur = plist->head->next;
	*data = plist->cur->data;
	return TRUE;
}

int LNext(List* plist, LData* data)
{
	if (plist->cur->next == plist->tail)
	{
		return FALSE;
	}
	
	plist->cur = plist->cur->next;
	*data = plist->cur->data;
	return TRUE;
}

int LPrev(List* plist, LData* data)
{
	if (plist->cur->prev == plist->head)
	{
		return FALSE;
	}
	
	plist->cur = plist->cur->prev;
	*data = plist->cur->data;
	return TRUE;
}

LData LRemove(List* plist)
{
	Node* rpos = plist->cur;
	LData rdata = rpos->data;
	
	plist->cur->prev->next = plist->cur->next;
	plist->cur->next->prev = plist->cur->prev;
	
	plist->cur = plist->cur->prev;
	
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
	int data;
	ListInit(&list);
	
	LInsert(&list, 1);
	LInsert(&list, 2);
	LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);
	LInsert(&list, 6);
	
	if (LFirst(&list, &data))
	{
		printf("%d ", data);
		while(LNext(&list, &data))
		{
			printf("%d ", data);
		}
	}
	
	if (LFirst(&list, &data))
	{
		if ( data % 2 == 0 )
		{
			LRemove(&list);
		}
		while(LNext(&list, &data))
		{
			if ( data % 2 == 0 )
			{
				LRemove(&list);
			}
		}
	}
	
	printf("\n\n");
	
	if (LFirst(&list, &data))
	{
		printf("%d ", data);
		while(LNext(&list, &data))
		{
			printf("%d ", data);
		}
	}
		
	printf("\n현재 데이터의 개수 %d\n", LCount(&list));
		
	return 0;
}
