#include<stdio.h>
#include<malloc.h>

#define true 1
#define false 0

typedef char bool;

typedef struct node
{
	int data;
	struct node *next;
}NODE,*PNODE,**PPNODE;

void push(PPNODE top,int no)
{
	PNODE newn=NULL;

	newn = (PNODE)malloc(sizeof(NODE));
	newn->data = no;
	newn->next = NULL;

	if(*top == NULL)
	{
		*top = newn;
		return;
	}

	newn->next = (*top);
	(*top) = newn;
}

int pop(PPNODE top)
{
	PNODE temp=NULL;
	int no;

	if(*top == NULL)
		return 0;

	temp = (*top);
	(*top) = (*top)->next;
	no = temp->data;
	free(temp);
	return no;
}

void display(PNODE head)
{
	PNODE temp = head;

	if(head == NULL)
		return;

	printf("\n");
	while(temp != NULL)
	{
		printf(" %d",temp->data);
		temp = temp->next;
	}
}

void enqueue(PPNODE front,PPNODE rear,int no)
{
	PNODE newn=NULL;

        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = no;
        newn->next = NULL;

        if((*front == NULL) || (*rear == NULL) )
        {
                (*front) = (*rear) = newn;
                return;
        }

        (*rear)->next = newn;
        (*rear) = newn;
}

int dequeue(PPNODE front,PPNODE rear)
{
	PNODE temp=(*front);
	int no;

	if((*front)==NULL)
		return 0;

	if((*front)->next == NULL)
	{
		(*front) = (*rear) = NULL;
	}
	else if((*front)->next != NULL)
	{
		(*front) = (*front)->next;
	}

	no = temp->data;
	free(temp);

	return no;
}




int main(void)
{
	PNODE S=NULL,f=NULL,r=NULL;
	int i=0,n=0,element=0,number=1;
	
	printf("\n Enter n: ");
	scanf("%d",&n);

	printf("\n Enter enqueue elements ");

	while(i < n)
	{
		scanf("%d",&element);
		enqueue(&f,&r,element);
		i++;
	}
	
	while(f != NULL)
	{
		element = dequeue(&f,&r);

		if(element == number)
			number++;
		else if(element != number)
			push(&S,element);
	}

	while(S != NULL)
	{
		element = pop(&S);

		if(number != element)
		{
			printf("\n No\n");
			break;
		}
		number++;
	}
	if(S==NULL)
	{
		printf("\n Yes \n");
	}
	return 0;
}
