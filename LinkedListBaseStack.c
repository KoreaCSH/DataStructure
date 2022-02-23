#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node {
	Data data;
	struct _node* next;
}Node;

typedef struct _listStack {
	Node* head;
}ListStack;

typedef ListStack Stack;

void StackInit(Stack* pstack)
{
	pstack->head = NULL;
}

int isEmpty(Stack* pstack)
{
	if (pstack->head == NULL)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void SPush(Stack* pstack, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = pstack->head;
	
	pstack->head = newNode;
}

Data SPop(Stack* pstack)
{
	Data rdata;
	Node* rNode;
	
	if (isEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}
	
	rdata = pstack->head->data;
	rNode = pstack->head;
	
	pstack->head = pstack->head->next;
	free(rNode);
	return rdata;
}

Data SPeek(Stack* pstack)
{
	if (isEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}
	return pstack->head->data;
}

int main(void)
{
	Stack stack;
	StackInit(&stack);
	
	SPush(&stack, 1);
	SPush(&stack, 2);
	SPush(&stack, 3);
	SPush(&stack, 4);
	SPush(&stack, 5);
	
	while (!isEmpty(&stack))
	{
		printf("%d\n", SPop(&stack));
	}
	
	return 0;
}
