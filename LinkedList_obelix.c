#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct node
{
	char digit;
	struct node  *next,*prev;
}NODE,*PNODE,**PPNODE;

void insertLast(PPNODE first,PPNODE last,char digit)
{
	PNODE newn=NULL;

	newn=(PNODE)malloc(sizeof(NODE));
	newn->digit = digit;
	newn->next = newn->prev = NULL;

	if((*first == NULL) && (*last == NULL))
	{
		(*first) = (*last) = newn;
		return;
	}
	
	(*last)->next = newn;
	newn->prev = (*last);
	(*last) = newn;
}

void insertFirst(PPNODE first,PPNODE last,char digit)
{
	PNODE newn=NULL;

        newn=(PNODE)malloc(sizeof(NODE));
        newn->digit = digit;
        newn->next = newn->prev = NULL;

        if((*first == NULL) && (*last == NULL))
        {
                (*first) = (*last) = newn;
                return;
        }

        (*first)->prev = newn;
        newn->next = (*first);
        (*first) = newn;
}


void display(PNODE head)
{
	printf("\n");
	while(head != NULL)
	{
		printf("%c=>",head->digit);
		head = head->next;
	}
	printf("\n");
}

void parse(PPNODE first,PPNODE last,int no)
{
	char ch;
	int digit;
	
	if(no == 0)
	{
		insertFirst(first,last,ch);
		return;
	}

	while(no != 0)
	{
		digit = no%10;
		ch = '0'+digit;
		no = no/10;
		insertFirst(first,last,ch);
	}
}

void add(PPNODE first,PPNODE last,int no)
{
	PNODE temp=(*last);
	int no2;
	char digit,carry='0';

	if((*first == NULL))
		return;

	while(temp!=NULL)
	{
		no = no+(temp->digit - '0');// + (carry - '0');
		digit = '0'+(no%10);
		no = no/10;

		temp->digit = digit;

		temp = temp->prev;
	}
	while(no != 0)
	{
		digit = '0' + (no%10);
		no = no/10;
		insertFirst(first,last,digit);
	}
}	

int main()
{
	PNODE head=NULL,tail=NULL;
	int no,choice=0;
	
	printf("Number : ");
	scanf("%d",&no);
	parse(&head,&tail,no);
	display(head);
	
	printf("\n number to add : ");

	scanf("%d",&no);
	add(&head,&tail,no);

	display(head);

	return 0;
}
