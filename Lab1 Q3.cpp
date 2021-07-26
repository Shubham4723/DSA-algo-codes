#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n;int *p;
	printf("Enter array size:\n");
	scanf("%d",&n);
	p=(int*)malloc(n*sizeof(int));
	printf("Enter array elements:");
	for(int i=0;i<n;i++)
	{
		scanf("%d",p+i);
	}
	printf("Elements in the order:even followed by odd:\n");
for(int i=0;i<n-1;i++)
{
	for(int j=0;j<n-i-1;j++)
	{
	if(p[j]%2!=0)
	{
		int temp=p[j];
		p[j]=p[j+1];
		p[j+1]=temp;
	}
}
}
for(int i=0;i<n;i++)
{
		printf("%d\n",p[i]);
}
return 0;
}
