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

// [����] ���� �ÿ��� ������ ��������� Ȯ���ϸ� �ȴٸ�,
// [ť] ���� �ÿ��� ť�� ����� ��(deQ �氡), ����á�� ��(enQ �Ұ�)�� ��� Ȯ���ؾ� �Ѵ�. 
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
	// ť�� ����á�� ������ EnQ �Ұ�. 
	if ( NextPosIdx(pq->rear) == pq->front )
	{
		exit(-1);
	}
	pq->rear = NextPosIdx(pq->rear);
	pq->arr[pq->rear] = data;
}

Data DeQ(Queue* pq)
{
	// ť�� ����� ������ DeQ �Ұ�.
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
	// Peek �� �켱������ ���� ���� ���� return �Ѵ�.
	// ��, front+1�� return �ؾ� �Ѵ�.
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
