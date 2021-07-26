#include<stdio.h>
#include<stdlib.h>


struct node
{
	int value;
	int row;
	int column;
	struct node *next;
};
struct node *head=NULL;


void initial()
{
	struct node *hn;
	hn=(struct node*)malloc(sizeof(struct node));
	if(!hn)
	{
		printf("memory out");
		return;
	}
	else
	{
		printf("rows: ");
		scanf("%d", &hn->row);
		printf("columns: ");
		scanf("%d", &hn->column);
		printf(" Positive non-repetitive values : ");
		scanf("%d", &hn->value);
		hn->next=NULL;
		head=hn;
	}
}


void insert()
{
	struct node *temp, *ptr;
	temp=(struct node*)malloc(sizeof(struct node));
	if(!temp)
		printf("memory out");
	else
	{
		printf("enter row number: ");
		scanf("%d", &temp->row);
		printf("enter column number: ");
		scanf("%d", &temp->column);
		printf("enter value number: ");
		scanf("%d", &temp->value);
		temp->next=NULL;
		if(head==NULL)
		{
			printf("initialization failed");
		}
		else
		{
			if(head->next==NULL)
				head->next=temp;
			else
			{
				ptr=head->next;
				while(ptr->next!=NULL)
					ptr=ptr->next;
				ptr->next=temp;
			}
		}
	}
}

void disp()
{
	struct node *ptr=head;
	if(!ptr)
	{
		printf("initials failed");
	}
	else
	{
		printf("Meta details: %d %d %d", ptr->row, ptr->column, ptr->value);
		printf("\ndetails: \n");
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
			printf("%d %d %d\n", ptr->row, ptr->column, ptr->value);
		}
	}
}

int main()
{
	int ch;
	printf("1. initialise \n2. insert\n3. display\n");
	do{
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:{
				initial();
				break;
			}
			case 2:{
				insert();
				break;
			}
			case 3:{
				disp();
				break;
			}
		}
		printf("\ncontinue?");
		scanf("%d", &ch);
	}while(ch==1);
	return 0;
}
