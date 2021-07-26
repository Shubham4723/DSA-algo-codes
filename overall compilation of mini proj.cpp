void insert(int *arr,int n)
{
	printf("Enter element to insert : ");
    scanf("%d", &num);
    printf("Enter the element position : ");
    scanf("%d", &pos);

    /* If position of element is not valid */
    if(pos > n+1 || pos <= 0)
    {
        printf("Invalid position! Please enter position between 1 to %d", n);
    }
    else
    {
    	printf("The original array elements are :\n");
	
         for(i = 0; i<n; i++) 
		{
           printf(" %d ", *(arr+i));
        }
        /* Make room for new array element by shifting to right */
        for(i=n; i>=pos; i--)
        {
            *(arr+i) = *(arr+i-1);
        }
        
        /* Insert new element at given position and increment of size */
        *(arr+pos-1) = num;
        n++; 

        /* Print array after insert operation */
        printf("Array elements after insertion : ");
        for(i=0; i<n; i++)
        {
            printf("%d\t", *(arr+i));
        }
    }

}

void delete(int arr*,int n)
{
   printf("Enter the element position to delete : ");
    scanf("%d", &pos);


    /* Invalid delete position */
    if(pos < 0 || pos > n)
    {
        printf("Invalid position! Please enter position between 1 to %d", n);
    }
    else
    {
    	printf("The original array elements are :\n");
	
        for(i = 0; i<n; i++) 
		{
          printf(" %d ", *(arr+i));
        }
        /* Copy next element value to current element */
        for(i=pos-1; i<n-1; i++)
        {
            *(arr+i) = *(arr+i+1);
        }

        /* Decrement array size by 1 */
        n--;

        /* Print array after deletion */
        printf("\nElements of array after delete are : ");
        for(i=0; i<n; i++)
        {
            printf("%d ", *(arr+i));
        }

    }
}	

void update(int *arr,int n)
{
	printf("enter the element position : \n");
  	scanf("%d",&k);
  	printf("enter the element : \n");
  	scanf("%d",&item);
  
	printf("The original array elements are :\n");
	
   for(i = 0; i<n; i++) {
      printf(" %d ", *(arr+i));
   }
    
   *(arr+k-1) = item;

   printf("\nThe array elements after updation :\n");
	
   for(i = 0; i<n; i++) 
   {
      printf(" %d ", *(arr+i));
  }
}

void anticlock_rotate(int* arr,int n)
 {
 	 int i, arr1[n], k;
 	 
 	 printf(" Enter the no of times the array is to be rotated = ");
 	 scanf("%d",&k);
 	 
 	 
 	 
 	 for(int i = 0; i < n; i++)
 	  {
 	  	arr1[i] = *(arr + i);
	   }
	   
	   printf("Array before anticlockwise rotation = \n ");
	   
	   for(int i=0; i < n; i++)
	     {
	     	printf("%d ",arr[i]);
		 }
		 
		 for(int i = 0; i < k; i++)
		  {
		  	int j=0, first;
		  	
		  	first = arr1[0];
		  	
		  	for(j = 0; j < n-1; j++)
		  	  {
		  	  	arr1[j] = arr1[j+1];
		  	  	
				}
		  	arr1[n-1] = first;
		  	
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
        
        for(j = n-1; j > 0; j--){    
            
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

void oddatbegining(int* arr,int n)
{ 
  	printf("The original array elements are :\n");
	
        for(i = 0; i<n; i++) 
		{
          printf(" %d ", *(arr+i));
        }
    int arr1[n], arr2[n];
    int j=0,k=0;
  for(i=0;i<n;++i)
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
   
	if(*(arr+i)==1)
	  {
	  arr1[j]=*(arr+i);
	  j++;
	  }
	
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
    	printf("\nThe array elements after operation are :\n");
	
        for(i = 0; i<n; i++) 
		{
          printf(" %d ", *(arr+i));
        } 
}

void oddatend(int* arr,int n)
{ 
  printf("enter the array elements\n");
    for (i = 0; i < n; i++) 
       {
          scanf("%d", arr + i);
		}
  	int i,arr1[n], arr2[n];
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
	  j++;
	  } 	
}
printf("array after operation \n");
for(i=0;i<k;i++)
{
*(arr+i)=arr2[i];
printf("%d ",*(arr+i));
}
j=0;
for(i=k;i<n;i++)
{
*(arr+i)=arr1[j];
printf("%d ",*(arr+i));
 j++;
}
}

void largest(int* arr,int n)
 {
    int i;
    for ( i = 1; i < n; i++) 
	{
        if (*arr < *(arr + i))//comparing the first element of the array with the rest
            *arr = *(arr + i);//storing the largest element 
    }
    printf("Largest number = %d", *arr);//printing the largest element
}

void smallest(int *arr,int n)
{
	int i;
  for ( i = 1; i < n; i++) 
  {
        if (*arr < *(arr + i))//comparing the first element of the array with the rest
            *arr = *arr;//storing the smallest element 
    }
    printf("Smallest number = %d", *arr);//printing the largest element	
}

void mean(int *arr,int n)
{
	int sum=0,i;
	float x=0.0;

	for(i=0;i<n;i++)
		sum=sum+*(arr+i);//sum of all elements of the array and store it in sum
		
	x=(float)sum/(float)n;
    printf("Mean\t= %f",x);	
}

void median(int *arr,int n)
{
	int a[n],i,j,t;
	float y=0.0;
	for(i=0;i<n;i++)
	{
		a[i]=*(arr+i);
	}
	for(i=0;i<n;i++)
    {
       for(j=i+1;j<n;j++)
       {
         if(a[i]>a[j])
         {
           t=a[i];
           a[i]=a[j];
           a[j]=t;
         }
       }
    }
     if(n%2==0)
      y=(float)(a[n/2]+a[(n-1)/2])/2;
     else
      y=a[(n-1)/2];
      printf("\nMedian\t= %f",y);
	
}

void mode(int *arr,int n)
{
	int a[n],b[n],i,j,k=0,max=0,mode,c=1;
	for(i=0;i<n;i++)
	{
		a[i]=*(arr+i);
	}
	for(i=0;i<n-1;i++)
   {
      mode=0;
    for(j=i+1;j<n;j++)
    {
      if(a[i]==a[j])
      {
        mode++;
      }
   }
   if((mode>max)&&(mode!=0))
   {
      k=0;
      max=mode;
      b[k]=a[i];
      k++;
   }
   else if(mode==max)
   {
     b[k]=a[i];
     k++;
   }
  }
  for(i=0;i<n;i++)
  {
    if(a[i]==b[i])
    c++;
  }
  if(c==n)
   printf("\nThere is no mode");
 else
  {
  printf("\nMode\t= ");
  for(i=0;i<k;i++)
  printf("%d ",b[i]);
  }
}
