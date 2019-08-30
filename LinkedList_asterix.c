#include<stdio.h>
#include<malloc.h>

typedef struct node
{
        int data;
        struct node  *next;
}NODE,*PNODE,**PPNODE;

void insertLast(PPNODE first,PPNODE last,int no)
{
        PNODE newn=NULL;

        newn=(PNODE)malloc(sizeof(NODE));
        newn->data = no;
        newn->next  = NULL;

        if((*first == NULL) && (*last == NULL))
        {
                (*first) = (*last) = newn;
                return;
        }

        (*last)->next = newn;
        (*last) = newn;
}

void insertFirst(PPNODE first,PPNODE last,int no)
{
        PNODE newn=NULL;

        newn=(PNODE)malloc(sizeof(NODE));
        newn->data = no;
        newn->next = NULL;

        if((*first == NULL) && (*last == NULL))
        {
                (*first) = (*last) = newn;
                return;
        }

        newn->next = (*first);
        (*first) = newn;
}


void display(PNODE head)
{
        printf("\n");
        while(head != NULL)
        {
                printf("%d=>",head->data);
                head = head->next;
        }
        printf("\n");
}

void arrangeAlternate(PPNODE first1,PPNODE first2)
{
	PNODE temp1=(*first1),temp2=(*first2),temp3=NULL;

	if(temp1==NULL || temp2==NULL)
		return;

	while(temp1!=NULL && (*first2)!=NULL)
	{
		temp3 = temp1->next;
		temp1->next = (*first2);

		(*first2) = (*first2)->next;
		temp1->next->next = temp3;

		temp1 = temp3;
	}
}

int main()
{
	PNODE head1,tail1,head2,tail2;
	int ino,ino2,icnt=0;

	head1=tail1=head2=tail2=NULL;

	printf("Number of elements in Link List 1 : ");
	scanf("%d",&ino);
	
	while(icnt < ino)
	{
		scanf("%d",&ino2);
		insertLast(&head1,&tail1,ino2);

		icnt++;
	}

	printf("Number of elements in Link List 2 : ");
        scanf("%d",&ino);

	icnt = 0;
        while(icnt < ino)
        {
                scanf("%d",&ino2);
                insertLast(&head2,&tail2,ino2);

                icnt++;
        }
	
	display(head1);
	display(head2);

	arrangeAlternate(&head1,&head2);
	display(head1);
	display(head2);

	return 0;
}
