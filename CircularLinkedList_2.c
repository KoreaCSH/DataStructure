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

// ����ü �ּҸ� �Ѱ��ִ� ���� �� �غ���! 
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

// strcmp(char str1, char str2) �Լ��� �� string�� ���� �� 0�� return 
// �Ʒ��� �Լ����� �ߺ��Ǵ� �ڵ�� �� ���� �ۼ����� ���� �� ���� ���̴�! 
Person* WhoisDangjik(List* plist, char name[], int day)
{
	// LFirst, LNext�� data->name == name �� Node�� ã�´�.
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
	Person* em;
	char name[MAX];
	ListInit(&list);
	int i;
	
	em = (Person*)malloc(sizeof(Person));
	strcpy(em->name, "��");
	em->num = 1111;
	LInsert(&list, em); 
	
	em = (Person*)malloc(sizeof(Person));
	strcpy(em->name, "��");
	em->num = 2222;
	LInsert(&list, em);
	
	em = (Person*)malloc(sizeof(Person));
	strcpy(em->name, "��");
	em->num = 3535;
	LInsert(&list, em); 
	
	em = (Person*)malloc(sizeof(Person));
	strcpy(em->name, "��");
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
	
	em = WhoisDangjik(&list, "��", 7);
	printf("%s \n", em->name); 

	return 0;
}
