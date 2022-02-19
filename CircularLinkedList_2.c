#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAX 10

typedef struct _person {
	char name[MAX];
	int num;
}Person;

// 구조체 주소를 넘겨주는 연습 더 해보자! 
typedef Person* LData;

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

// tail에 데이터 추가 
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

// head 부분에 데이터 추가 
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
	// 원형연결리스트이므로 리스트의 마지막 노드임을 검사하는 코드가 존재하지 않는다. 
	if (plist->tail == NULL)
	{
		return FALSE;
	}
	plist->before = plist->cur;
	plist->cur = plist->cur->next;
	
	*pdata = plist->cur->data;
	return TRUE;
}

// strcmp(char str1, char str2) 함수는 두 string이 같을 때 0을 return 
// 아래의 함수에서 중복되는 코드는 한 번의 작성으로 줄일 수 있을 것이다! 
Person* WhoisDangjik(List* plist, char name[], int day)
{
	// LFirst, LNext로 data->name == name 인 Node를 찾는다.
	Person* em;
	int i;
	if (LFirst(plist, &em))	
	{
		if (strcmp(em->name, name) == 0)
		{
			for ( i = 0; i < day; i++ )
			{
				LNext(plist, &em);
			}
			return em;
		}
		for ( i = 0; i < LCount(plist)-1; i++ )
		{
			LNext(plist, &em);
			if (strcmp(em->name, name) == 0)
			{
				for ( i = 0; i < day; i++ )
				{
					LNext(plist, &em);
				}
				return em;
			}
		}
	}
}

LData LRemove(List* plist)
{
	Node* rpos = plist->cur;
	LData rdata = rpos->data;
	
	// 예외 ( tail 이 삭제할 노드인 cur 을 가리킬 때)
	if ( rpos == plist->tail )
	{
		// 예외1) 삭제할 노드가 리스트의 마지막 노드일 때
		if (plist->tail == plist->tail->next)
		{
			plist->tail = NULL;
		} 
		// 예외2) 삭제할 노드를 tail 이 가리키는 경우
		else
		{
			plist->tail = plist->before;
		} 
	}
	
	// 일반적인 경우
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
	Person* em;
	char name[MAX];
	ListInit(&list);
	int i;
	
	em = (Person*)malloc(sizeof(Person));
	strcpy(em->name, "최");
	em->num = 1111;
	LInsert(&list, em); 
	
	em = (Person*)malloc(sizeof(Person));
	strcpy(em->name, "유");
	em->num = 2222;
	LInsert(&list, em);
	
	em = (Person*)malloc(sizeof(Person));
	strcpy(em->name, "김");
	em->num = 3535;
	LInsert(&list, em); 
	
	em = (Person*)malloc(sizeof(Person));
	strcpy(em->name, "배");
	em->num = 4454;
	LInsert(&list, em); 
	
	if(LFirst(&list, &em))
	{
		printf("%s %d  ", em->name, em->num);
		printf("\n");
		
		for ( i = 0; i < LCount(&list)-1; i++ )
		{
			if (LNext(&list, &em)) {
				printf("%s %d  \n", em->name, em->num);	
			}
		}
	}
	
	em = WhoisDangjik(&list, "배", 7);
	printf("%s \n", em->name); 

	return 0;
}
