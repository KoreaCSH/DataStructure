#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node {
	Data data;
	struct _node* next;
}Node;

typedef struct _lqueue {
	Node* front;
	Node* rear;
}LQueue;

typedef LQueue Queue;

void QInit(Queue* pq)
{
	pq->front = NULL;
	pq->rear = NULL;
}

int QisEmpty(Queue* pq)
{
	if (pq->front == NULL)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void EnQ(Queue* pq, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data = data;
	
	if (QisEmpty(pq))
	{
		pq->front = newNode;
		pq->rear = newNode;
	}
	else
	{
		pq->rear->next = newNode;
		pq->rear = newNode;
	}
}

Data DeQ(Queue* pq)
{
	Node* delNode;
	Data rdata;
	
	if (QisEmpty(pq))
	{
		exit(-1);
	}
	
	delNode = pq->front;
	rdata = delNode->data;
	pq->front = pq->front->next;
	
	free(delNode);
	return rdata;
}

Data QPeek(Queue* pq)
{
	if(QisEmpty(pq))
	{
		exit(-1);
	}
	return pq->front->data;
}

int main(void)
{
	Queue q;
	QInit(&q);
	
	EnQ(&q, 1);
	EnQ(&q, 2);
	EnQ(&q, 3);
	printf("현재 가장 높은 우선순위를 가진 수: %d\n", QPeek(&q));
	EnQ(&q, 4);
	EnQ(&q, 5);
	
	while(!QisEmpty(&q))
	{
		printf("%d ", DeQ(&q));
	}
	
	return 0;
}
