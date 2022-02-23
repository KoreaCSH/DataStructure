#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define STACK_LEN 100

typedef int Data;

typedef struct _arraystack {
	Data stackArr[STACK_LEN];
	int top;
} ArrayStack;

typedef ArrayStack Stack;

void StackInit(Stack* pstack)
{
	pstack->top = -1;
}

int isEmpty(Stack* pstack)
{
	if ( pstack->top == -1 )
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
	(pstack->top)++;
	pstack->stackArr[pstack->top] = data;
}

Data SPop(Stack* pstack)
{
	int ridx;
	
	if ( isEmpty(pstack) )
	{
		printf("Stack Memory Error!\n");
		exit(-1);
	}
	
	ridx = pstack->top;
	(pstack->top)--;
	
	return pstack->stackArr[ridx];
}

Data SPeek(Stack* pstack)
{
	if ( isEmpty(pstack) )
	{
		printf("Stack Memory Error!\n");
		exit(-1);
	}
	return pstack->stackArr[pstack->top];
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
	
	while ( !isEmpty(&stack) )
	{
		printf("%d\n", SPop(&stack));
	}
				
	return 0;
}
