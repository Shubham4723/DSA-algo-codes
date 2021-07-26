#include <stdio.h>
#include<stdlib.h>

void anticlock_rotate(int* arr,int n)
 {
 	 int i, arr1[n], k;
 	 
 	 printf(" Enter the no of times the array is to be rotated = ");
 	 scanf("%d",&k);
 	 
 	 //k = k % n;
 	 
 	 for(int i = 0; i < n; i++)
 	  {
 	  	arr[i] = *(arr + i);
	   }
	   
	   printf("Array before anticlockwise rotation = \n ");
	   
	   for(int i=0; i < n; i++)
	     {
	     	printf("%d ",arr[i]);
		 }
		 
		 for(int i = n-1; i > k; i--)
	  {    
        int j, last;    
        
        last = arr1[n-1];    
        
        for(j = n-1; j > 0; j--){    
            
            arr1[j] = arr1[j-1];    
        }    
        
        arr1[0] = last;    
      }    
		  
		  printf("\n");
		  
		printf("Array after anticlockwise rotation: \n");    
    for(int i = 0; i< n; i++)
	  {    
        printf("%d ", arr1[i]);    
		  
       }
       
}
 
void clock_rotate(int* arr,int n)
{ 
    int i, arr1[n], k;
  
   printf(" Enter the no of times the array is to be rotated = ");
   scanf("%d",&k);
   
   
     for(int i = 0; i < n; i++)
       {
       	 arr1[i] = *(arr + i);
       	 
	   }
	   
	   printf("Array before clockwise rotation: \n");    
    for(int i = 0; i< n; i++)
	  {    
        printf("%d ", arr1[i]);    
    }
   
     for(int i = 0; i < k; i++)
	  {    
        int j, last;    
        
        last = arr1[n-1];    
        
        for(j = n-1; j > 0; j--)
		{    
            
            arr1[j] = arr1[j-1];    
        }    
        
        arr1[0] = last;    
    }    
        
    printf("\n");    
    
    
     printf("Array after clockwise rotation: \n");    
    for(int i = 0; i< n; i++)
	  {    
        printf("%d ", arr1[i]);    
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
  for (i = 0; i < n; ++i) 
       {
          scanf("%d", arr + i);
		}
      
      
      // clock_rotate(arr,n);
 /* printf("1. for clockwise rotation");
  printf("2. for anticlockwise rotation");
  printf("enter the choice for operation");
  scanf("%d",&choice);  */
       anticlock_rotate(arr,n);
  
  
    return 0;
     
     
} 
