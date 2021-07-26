#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *prev;
	int data;
	struct node *next;
};
struct node *head=NULL;
struct node *tail=NULL;
void insert_beg()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	if(!temp)
	{
		printf("memory out");
		return;
	}
	printf("enter data: ");
	scanf("%d", &temp->data);
	if(head==NULL)
	{
		head=tail=temp;
		temp->next=temp->prev=NULL;
	}
	else
	{
		temp->next=head;
		head->prev=temp;
		head=temp;
		temp->prev=NULL;
	}
}
void insert_end()
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	if(!temp)
	{
		printf("memory out");
		return;
	}
	printf("enter data: ");
	scanf("%d", &temp->data);
	if(head==NULL)
	{
		head=tail=temp;
		temp->next=temp->prev=NULL;
	}
	else
	{
		struct node *ptr;
		ptr=head;
		while(ptr->next!=NULL)
			ptr=ptr->next;
		ptr->next=temp;
		temp->prev=ptr;
		temp->next=NULL;
		tail=temp;
	}
}
int count()
{
	struct node *ptr;
	int c=0;
	if(head==NULL)
		return 0;
	else
	{
		for(ptr=head;ptr!=NULL;ptr=ptr->next,c++);
		return c;
	}
}
void insert_pos()
{
	int pos,i;
	struct node *ptr, *temp;
	printf("enter position [1:%d]: ", count());
	scanf("%d", &pos);
	if(pos==1)
	{
		insert_beg();
	}
	else if(pos==count()+1)
	{
		insert_end();
	}
	else if(pos>1&&pos<=count())
	{
		for(i=1,ptr=head;ptr!=NULL;ptr=ptr->next,i++)
		{
			if(i==pos)
			{
				temp=(struct node*)malloc(sizeof(struct node));
				if(!temp)
				{
					printf("memory out\n");
					return;
				}
				printf("enter data: ");
				scanf("%d", &temp->data);
				ptr->prev->next=temp;
				temp->prev=ptr->prev;
				temp->next=ptr;
				ptr->prev=temp;	
			}
		}
	}
	else
		printf("invalid position\n");
}
void disp()
{
	struct node *ptr;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	ptr=head;
	printf("NULL<-->(head)");
	while(ptr!=NULL)
	{
		printf("%d<-->", ptr->data);
		ptr=ptr->next;
	}
	printf("NULL");
	printf("\n reverse print\n");
	ptr=tail;
	printf("NULL<-->(tail)");
	while(ptr!=NULL)
	{
		printf("%d<-->", ptr->data);
		ptr=ptr->prev;
	}
	printf("NULL\n");
}
void search()
{
	int ele;
	struct node *ptr;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	ptr=head;
	printf("search: ");
	scanf("%d", &ele);
	while(ptr!=tail)
	{
		if(ptr->data==ele)
		{
			printf("element present\n");
			return;
		}
		ptr=ptr->next;
	}
	printf("element not found\n");
}
int check()
{
	if(head==NULL)
		return 0;
	return 1;
}
void del_end()
{
	if(!tail)
	{
    	printf("No node exist\n");
    	return;
  	}
  	if(tail == head)
    {
    	tail = head = NULL;
    	return;
  	}
  	struct node *temp = tail;
	temp->prev->next = NULL;
	tail = temp->prev;
}
void del_beg()
{
	struct node *ptr;
	if(head==NULL)
	{
		printf("list is empty\n");
		return;
	}
	head=head->next;
	head->prev=NULL;
}
void del_data()
{
	struct node *temp, *ptr;
	int d;
	if(!check())
		printf("list is empty");
	else
	{
		printf("Enter data: ");
		scanf("%d", &d);
		if(head->data==d)
		{
			del_beg();
			return;
		}
		ptr=head;
		while(ptr!=NULL&&ptr->data!=d)
		{
			temp=ptr;
			ptr=ptr->next;
		}
		if(ptr==NULL)
		{
			printf("element not found");
			return;
		}
		else if(ptr->next!=NULL)
		{
			temp->next=ptr->next;
			ptr->next->prev=temp;
		}
		else
		{
			temp->next=NULL;
			tail=temp;
		}
		free(ptr);
	}
}
void del_pos()
{
        int i,pos;
        struct node *temp,*ptr;
        if(head==NULL)
                printf("List is Empty");
        else
        {
                printf("\nEnter the position: ");
                scanf("%d",&pos);
                if(pos==0)
                	del_beg();
                else
                {
                        ptr=head;
                        for(i=0;i<pos;i++)
                        {
                                temp=ptr;
                                ptr=ptr->next ;
                                if(ptr==NULL)
                                {
                                        printf("Position not Found");
                                        return;
                                }
                        }
                        if(ptr->next!=NULL)
                        {
                        	temp->next =ptr->next ;
                        	ptr->next->prev=temp;
                        }
                        else
                        {
                        	temp->next=NULL;
                        	tail=temp;
						}
                }
        }
}
int main()
{
	int ch;
	printf("1. insert_end\n2. insert_beginning\n3. insert_position\n4. display\n5. search\n6. delete_end\n");
	printf("7. delete_beginning\n8. count\n9. delete_key\n10. delete_pos\n11. check_empty\n");
	do{
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:{
				insert_end();
				break;
			}
			case 2:{
				insert_beg();
				break;
			}
			case 3:{
				insert_pos();
				break;
			}
			case 4:{
				disp();
				break;
			}
			case 5:{
				search();
				break;
			}
			case 6:{
				del_end();
				break;
			}
			case 7:{
				del_beg();
				break;
			}
			case 8:{
				printf("total nodes: %d\n", count());
				break;
			}
			case 9:{
				del_data();
				break;
			}
			case 10:{
				del_pos();
				break;
			}
			case 11:{
				if(check())
					printf("list is not empty\n");
				else
					printf("list is empty\n");
				break;
			}
		}
		printf("continue? ");
		scanf("%d", &ch);
	}while(ch==1);
	return 0;
}

