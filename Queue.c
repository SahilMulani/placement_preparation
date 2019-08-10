#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node
{
	struct node *prev;
	int data;
	struct node *next;
};

typedef struct node NODE;
NODE *front=NULL,*rear=NULL;

void Enqueue(int no)
{
	NODE *newn=(NODE *)malloc(sizeof(NODE));
	NODE *temp = front;
	newn->data = no;
	newn->next = newn->prev = NULL;

	if(front == NULL)
	{
		rear=front = newn;
		return;
	}
	
	newn->next = front;
	front->prev = newn;
	front = newn;

}

void Dequeue()
{
	NODE *temp = rear;

	if(rear == NULL)
		return;
	
	rear = rear->prev;
	
	if(rear != NULL)
	{
		rear->next = NULL;
		free(temp);
	}
	else
	{
		front = NULL;
	}
}

void peek()
{
	NODE *temp = front;

	if(front == NULL)
		return;
	printf("\n");
	while(temp != NULL)
	{
		printf(" %d ",temp->data);
		temp = temp->next;
	}
}


int main(void)
{
	int choice,no;

	while(1)
	{
		printf("\nEnter choice 1.Enqueue 2.Dequeue 3.peek 4.exit");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:printf("\nEnter Element ");
			       scanf("%d",&no);
			       Enqueue(no);
			       break;

			case 2:Dequeue();
			       break;

			case 3:peek();
			       break;
			case 4:exit(0);
			default:break;
		}

	}
}

