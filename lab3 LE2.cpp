#include<stdio.h>
#include<stdlib.h>
struct node
{
	int power;
	int coeff;
	struct node *next;
};
struct node *p1=NULL;//polynomial 1
struct node *p2=NULL;
struct node *r=NULL;
void insert(int n)
{
	struct node *temp, *t;
	r=(struct node*)malloc(sizeof(struct node));
	switch(n)
	{
		case 1:{
			do{
				temp=(struct node*)malloc(sizeof(struct node));
				if(!temp)
				{
					printf("memory out");
					return;
				}
				printf("coeff: ");
				scanf("%d", &temp->coeff);
				printf("power: ");
				scanf("%d", &temp->power);
				temp->next=NULL;
				if(p1==NULL)
					p1=temp;
				else
				{
					t=p1;
					while(t->next!=NULL)
						t=t->next;
					t->next=temp;
				}
				printf("continue insert poly 1?");
				scanf("%d", &n);
			}while(n==1);
			break;
		}
		case 2:{
			do{
				temp=(struct node*)malloc(sizeof(struct node));
				if(!temp)
				{
					printf("memory out");
					return;
				}
				printf("coeff: ");
				scanf("%d", &temp->coeff);
				printf("power: ");
				scanf("%d", &temp->power);
				temp->next=NULL;
				if(p2==NULL)
					p2=temp;
				else
				{
					t=p2;
					while(t->next!=NULL)
						t=t->next;
					t->next=temp;
				}
				printf("continue insert poly 2?");
				scanf("%d", &n);
			}while(n==1);			
			break;
		}
	}
}
void add()
{
	struct node *ptr1, *ptr2, *ptr3;
	ptr1=p1;
	ptr2=p2;
	ptr3=r;
	printf("in add function");
	while(ptr1!=NULL&&ptr2!=NULL)
	{
		if(ptr1->power>ptr2->power)
		{
			ptr3->power=ptr1->power;
			ptr3->coeff=ptr1->coeff;
			ptr1=ptr1->next;
			printf("%dX^%d", ptr3->coeff, ptr3->power);
		}
		else if(ptr1->power<ptr2->power)
		{
			ptr3->power=ptr2->power;
			ptr3->coeff=ptr2->coeff;
			ptr2=ptr2->next;
			printf("%dX^%d", ptr3->coeff, ptr3->power);
		}
		else
		{
			ptr3->power=ptr1->power;
			ptr3->coeff=ptr1->coeff+ptr2->coeff;
			ptr1=ptr1->next;
			ptr2=ptr2->next;
			printf("%dX^%d", ptr3->coeff, ptr3->power);
		}
		ptr3->next=(struct node*)malloc(sizeof(struct node));
		ptr3=ptr3->next;
		ptr3->next=NULL;
	}
	while(ptr1!=NULL||ptr2!=NULL)
	{
		if(ptr1!=NULL)
		{
			ptr3->power=ptr1->power;
			ptr3->coeff=ptr1->coeff;
			ptr1=ptr1->next;
			printf("%dX^%d", ptr3->coeff, ptr3->power);
		}
		if(ptr2!=NULL)
		{
			ptr3->power=ptr2->power;
			ptr3->coeff=ptr2->coeff;
			ptr2=ptr2->next;
			printf("%dX^%d", ptr3->coeff, ptr3->power);
		}
		ptr3->next=(struct node*)malloc(sizeof(struct node));
		ptr3=ptr3->next;
		ptr3->next=NULL;
	}
}
void disp()
{
	struct node *ptr=r;// r is the 3rd polynomial the result
	printf("\n");
	if(!ptr)
	{
		printf("no result");
		return;
	}
	while(ptr->next!=NULL)
	{
		printf(" %dX^%d ", ptr->coeff, ptr->power);
		ptr=ptr->next;
		if(ptr!=NULL)
			printf(" + ");
	}
}
int main()
{
	int ch;
	printf("1. insert poly 1\n2. insert poly 2\n3. result\n");
	do{
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:{
				insert(ch);
				break;
			}
			case 2:{
				insert(ch);
				break;
			}
			case 3:{
				add();
				disp();
				break;
			}
		}
		printf("continue main?");
		scanf("%d", &ch);
	}while(ch==1);
	return 0;
}
