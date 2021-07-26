#include<stdio.h>
#include<conio.h>
#define max 7
int queue[max];
int front=-1, rear=-1;
int insert(void);
int delete_element(void);
int peek(void);
void display(void);
int main()
{
    int option;
    do
        {
            printf("\n\n***MAIN MENU*");
            printf("\n1.INSERT AN ELEMENT IN QUEUE\n2.DELETE THE FRONT ELEMENT\n3.PEEK ELEMENT\n4.DISPLAY QUEUE\n5.EXIT");
            printf("\nEnter you Option:");
            scanf("%d",&option);
            switch(option)
            {
            case 1:
                insert();
                break;
            case 2:
                delete_element();
                break;
            case 3:
                peek();
                printf("\nTop Element of QUEUE is %d",queue[front]);
                break;
            case 4:
                display();
                break;
            }
        }
        while(option!=5);
        return 0;
}
int insert()
        {
            int num;
            printf("\n Enter the number to be inserted:\t");
            scanf("%d",&num);
            if(rear==max-1)
            {
                printf("\nQUEUE OVERFLOW");
                return -1;
            }
            else if(front==-1 && rear==-1)
                front=rear=0;
            else
                rear=rear+1;
            queue[rear]=num;
                printf("\nThe Element Inserted is:\t%d",queue[rear]);
        }
int delete_element()
        {
            int val;
            if(front==-1|| front>rear)
                {
                    printf("\nQueue Underflow");
                    return -1;
                }
            else
            {
                val=queue[front];
                front=front+1;
                if(front>rear)
                    front=rear=-1;
                printf("\nThe deleted element is:\t%d",val);
            }
        }
        int peek()
        {
            if(front==-1||front>rear)
            {
                printf("\nQueue is empty");
            return -1;
            }
            else
            {
                return queue[front];
            }
        }
        void display()
        {
            int i;
            printf("\n");
            if(front==-1||front>rear)
                printf("\nQueue is empty");
            else
            {
                for(i=front;i<=rear;i++)
                    printf("\t%d",queue[i]);
            }
        }

