#include <stdio.h>
#include<stdlib.h>
void evenatend(int* arr,int n)
{ int i,arr1[n], arr2[n];
  int j=0,k=0;
  for(i=0;i<n;++i)
  {
   {
	 if(*(arr+i)>=2)
    { if(*(arr+i)%2!=0)
      { arr1[j]=*(arr+i);
        j++;
	  }
	  else
	{ arr2[k]=*(arr+i);
	  k++;
	}
    }
}
	if(*(arr+i)==1)
	  {
	  arr1[j]=*(arr+i);
	  j++;}

  
  	
}
for(i=0;i<j;i++)
{
*(arr+i)=arr1[i];

}
k=0;
for(i=j;i<n;i++)
{
*(arr+i)=arr2[k];

 k++;
}
}

void evenatbegining(int* arr,int n)
{ int i,arr1[n], arr2[n];
  int j=0,k=0;
  for(i=0;i<n;++i)
  {
   {
	 if(*(arr+i)>=2)
    { if(*(arr+i)%2!=0)
      { arr1[j]=*(arr+i);
        j++;
	  }
	  else
	{ arr2[k]=*(arr+i);
	  k++;
	}
    }
}
	if(*(arr+i)==1)
	  {
	  arr1[j]=*(arr+i);
	  j++;}

  
  	
}
for(i=0;i<k;i++)
{
*(arr+i)=arr2[i];
printf("%d\n",*(arr+i));
}
j=0;
for(i=k;i<n;i++)
{
*(arr+i)=arr1[j];
printf("%d\n",*(arr+i));
 j++;
}
}


void display(int* arr,int n)
{ int i;
  for(i=0;i<n;i++)
  {printf("%d\n",*(arr+i));
  }
}

int main()
{ 
  int n,i,choice;
  int *arr;
  printf("enter the size of array");
  scanf("%d",&n);
  arr=(int*)malloc(n*sizeof(int));
  printf("enter the array elements");
  for (i = 0; i < n; ++i) {
        scanf("%d", arr + i);}

  printf("1. for even at the begining");
  printf("2. for even at the end");
  printf("enter the choice for operation");
  scanf("%d",&choice);
  switch(choice)
  {
  case 1:
    evenatbegining(arr,n);
    break;
  case 2:
  	evenatend(arr,n);
  	break;
  case 3:
  	display(arr,n);
  	break;
  default:
  	 printf("wrong choice");
  }
    }
