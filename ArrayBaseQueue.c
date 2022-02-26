#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define Q_LEN 101

typedef int Data;

typedef struct _Queue {
	Data arr[Q_LEN];
	int front;
	int rear;
}Queue; 

void QInit(Queue* pq)
{
	pq->front = 0;
	pq->rear = 0;
}

// [스택] 구현 시에는 스택이 비었는지만 확인하면 된다면,
// [큐] 구현 시에는 큐가 비었을 때(deQ 뷸가), 가득찼을 때(enQ 불가)를 모두 확인해야 한다. 
int QisEmpty(Queue* pq)
{
	if (pq->front == pq->rear)
	{
		return TRUE;
	}
	else 
	{
		return FALSE;
	}
}

int NextPosIdx(int pos)
{
	if (pos == Q_LEN-1) 
	{
		return 0;
	}
	else
	{
		return pos+1;
	}
} 

void EnQ(Queue* pq, Data data)
{	
	// 큐가 가득찼을 때에는 EnQ 불가. 
	if ( NextPosIdx(pq->rear) == pq->front )
	{
		exit(-1);
	}
	pq->rear = NextPosIdx(pq->rear);
	pq->arr[pq->rear] = data;
}

Data DeQ(Queue* pq)
{
	// 큐가 비었을 때에는 DeQ 불가.
	if ( QisEmpty(pq) )
	{
		exit(-1);
	} 
	pq->front = NextPosIdx(pq->front);
	return pq->arr[pq->front];
}

Data QPeek(Queue* pq)
{
	if ( QisEmpty(pq) )
	{
		exit(-1);
	}
	// Peek 는 우선순위가 가장 높은 것을 return 한다.
	// 즉, front+1을 return 해야 한다.
	return pq->arr[NextPosIdx(pq->front)];
}

int main(void)
{
	Queue q;
	QInit(&q);
	
	EnQ(&q, 1);
	EnQ(&q, 2);
	EnQ(&q, 3);
	EnQ(&q, 4);
	EnQ(&q, 5);
	
	while ( !QisEmpty(&q) )
	{
		printf("%d ", DeQ(&q));
	}
	
	return 0;
}
