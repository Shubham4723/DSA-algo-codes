#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int power;
	int coeff;
	struct node *next;
};
struct node *head = NULL;
void insert()
{
	struct node *temp, *ptr;
	temp=(struct node*)malloc(sizeof(struct node));
	if(!temp)
		printf("memory out");
	else
	{
		printf("enter coeff: ");
		scanf("%d", &temp->coeff);
		printf("enter power: ");
		scanf("%d", &temp->power);
		temp->next=NULL;
		if(head==NULL)
			head = temp;
		else
		{
			ptr=head;
			while(ptr->next!=NULL)
				ptr=ptr->next;
			ptr->next=temp;
		}
	}
}
void disp()
{
	struct node *temp=head;
	if(!temp)
		printf("polunomial is empty (0)");
	else
	{
		while(temp!=NULL)
		{
			printf("%dX^%d", temp->coeff, temp->power);
			temp=temp->next;
			if(temp!=NULL)
				printf(" + ");
		}
	}
}
int main()
{
	int ch;
	printf("1. insert\n2. display\n");
	do{
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:{
				insert();
				break;
			}
			case 2:{
				disp();
				break;
			}
		}
		printf("\ncontinue?");
		scanf("%d", &ch);
	}while(ch==1);
	return 0;
}
