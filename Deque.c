#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node {
	Data data;
	struct _node* next;
	struct _node* prev;
}Node;

typedef struct _deque {
	Node* head;
	Node* tail;
	int numOfData;
}Deque;

void DQInit(Deque* pdq)
{
	pdq->head = NULL;
	pdq->tail = NULL;
	pdq->numOfData = 0;
}

int DQisEmpty(Deque* pdq)
{
	if (pdq->head == NULL)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void DQAddFirst(Deque* pdq, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->prev = NULL;
	newNode->next = pdq->head;
	
	if (DQisEmpty(pdq))
	{
		pdq->tail = newNode;
	}
	else
	{
		pdq->head->prev = newNode;
	}
	pdq->head = newNode;
	(pdq->numOfData)++;
}

void DQAddLast(Deque* pdq, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	newNode->prev = pdq->tail;
	newNode->next = NULL;
	
	if (DQisEmpty(pdq))
	{
		pdq->head = newNode;
	}
	else
	{
		pdq->tail->next = newNode;
	}
	pdq->tail = newNode;
	(pdq->numOfData)++;
}

Data DQRemoveFirst(Deque* pdq)
{
	Node* DelNode;
	Data rdata;
	
	if (DQisEmpty(pdq))
	{
		return -1;
	}
	
	DelNode = pdq->head;
	rdata = DelNode->data;
	
	pdq->head = pdq->head->next;
	free(DelNode);
	
	if (pdq->head == NULL) // head와 tail 이 같은 노드를 가리키고 있다 == 즉, 마지막 노드. 
	{
		pdq->tail = NULL; 
	}
	else
	{
		pdq->head->prev = NULL;
	}
	(pdq->numOfData)--;
	return rdata;
}

Data DQRemoveLast(Deque* pdq)
{
	Node* DelNode;
	Data rdata;
	
	if (DQisEmpty(pdq))
	{
		return -1;
	}
	
	DelNode = pdq->tail;
	rdata = DelNode->data;
	
	pdq->tail = pdq->tail->prev;
	free(DelNode);
	
	if(pdq->tail == NULL)
	{
		pdq->head = NULL;
	}
	else
	{
		pdq->tail->next = NULL;
	}
	(pdq->numOfData)--;
	return rdata;
}

Data DQGetFirst(Deque* pdq)
{
	if(DQisEmpty(pdq))
	{
		return -1;
	}
	return pdq->head->data;
}

Data DQGetLast(Deque* pdq)
{
	if(DQisEmpty(pdq))
	{
		return -1;
	}
	return pdq->tail->data;
}

int DQSize(Deque* pdq)
{
	return pdq->numOfData;
}

int main(void)
{
	Deque dq;
	DQInit(&dq);
	
	char str[20];
	int n, i, num;
	scanf("%d", &n);
	getc(stdin);
	
	for ( i = 0; i < n; i++ )
	{
		gets(str);
		if ( strncmp(str, "push_front", 10) == 0 )
		{
			num = atoi(str+11);
			DQAddFirst(&dq, num);
		}
		else if ( strncmp(str, "push_back", 9) == 0 )
		{
			num = atoi(str+10);
			DQAddLast(&dq, num);
		}
		else if ( strcmp(str, "pop_front") == 0 )
		{
			printf("%d\n", DQRemoveFirst(&dq));
		}
		else if ( strcmp(str, "pop_back") == 0 )
		{
			printf("%d\n", DQRemoveLast(&dq));
		}
		else if ( strcmp(str, "size") == 0 )
		{
			printf("%d\n", DQSize(&dq));
		}
		else if ( strcmp(str, "empty") == 0 )
		{
			printf("%d\n", DQisEmpty(&dq));
		}
		else if ( strcmp(str, "front") == 0 )
		{
			printf("%d\n", DQGetFirst(&dq));
		}
		else if ( strcmp(str, "back") == 0 )
		{
			printf("%d\n", DQGetLast(&dq));
		}
	}
				
	return 0;
}
