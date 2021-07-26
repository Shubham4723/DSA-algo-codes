#include <stdio.h>
void swap(int* n1, int* n2)
{
    int temp;
    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}
int main()
{
    int x=10,y=20,z=30;
    
    swap(&x,&z);
    swap(&y,&z);
    
    printf("x=%d,y=%d,z=%d",x,y,z);

    return 0;
}
