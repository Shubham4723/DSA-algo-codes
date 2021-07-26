#include <stdio.h> 
#include<iostream>
#include <stdlib.h> 
#include<time.h>
int *randomNumberGen(int n) {int i; int *arr = (int *)malloc(sizeof(int) * n); for (i = 0; i < n; i++) {
arr[i] = rand();
}
return arr;
}
void swap(int *a, int *b)
{
int tmp = *a;
*a = *b;
*b = tmp;
}
void heapify(int *arr, int n, int i)
{
int max = i;
int leftChild = 2 * i + 1; int rightChild = 2 * i + 2;
if (leftChild < n && arr[leftChild] > arr[max]) max = leftChild;
if (rightChild < n && arr[rightChild] > arr[max]) max = rightChild;
if (max != i)
{
swap(&arr[i], &arr[max]); heapify(arr, n, max);
}}
void heapSort(int *arr, int n)
{ int i;
for (i = n / 2 - 1; i >= 0; i--)
 
heapify(arr, n, i);
for (i = n - 1; i >= 0; i--)
{
swap(&arr[0], &arr[i]); heapify(arr, i, 0);
}
}
void sortDescending(int *arr,int n)
{
int i, key, j;
for (i = 1; i < n; i++) { key = arr[i];
j = i - 1;
while (j >= 0 && arr[j] < key) { arr[j + 1] = arr[j];
j = j - 1;
}
arr[j + 1] = key;
}
}
void printArray(int *arr,int n)
{
  int i;
for(i=0;i<n;i++)
{
cout<<arr[i]; 
cout<<"\n";
}
int largest(int *arr, int n)
{
int i;
int max = arr[0]; for (i = 1; i < n; i++) if (arr[i] > max) max = arr[i];
cout<<"Maximum element is: "<<max;
}
 
void delete(int *arr,int n)
{
int last = arr[n - 1]; arr[0] = last; heapSort(arr,n);
}
void insert(int *arr,int n,int key)
{
arr[n-1] = key; heapSort(arr, n);
}
void replace(int *arr,int n)
{
int k,in;
cout<<"Enter Element and Index of Replacement:\n"; cin>>k>>in;
arr[in]=k; heapSort(arr,n);
}
int main()
{
int ncase,n; do
{
cout<<"\t\tMAX-HEAP & PRIORITY QUEUE MENU\n";
cout<<"0. Quit\n";
cout<<"1. n Random numbers=>Array\n"; cout<<"2. Display the Array\n";
cout<<"3. Sort the Array in Ascending Order by using Max-Heap Sort technique\n";
cout<<"4. Sort the Array in Descending Order by using any algorithm\n";
cout<<"5. Time Complexity to sort ascending of random data\n";
 
cout<<"6. Time Complexity to sort ascending of data already sorted in ascending order\n";
cout<<"7. Time Complexity to sort ascending of data already sorted in descending order\n"; cout<<"8. Time Complexity to sort ascending all Cases (Data Ascending, Data in Descending & Random Data) in Tabular form for values n=5000 to 50000, step=5000\n";
cout<<"9. Extract largest element\n";
cout<<"10. Replace value at a node with new value\n"; cout<<"11. Insert a new element\n";
cout<<"12. Delete an element\n"; cout<<"\n\nEnter the CASE:"; cin>>ncase;
cin>>ncase; switch(ncase)
{
case 0: cout<<"Exit !!!\n"; exit(1);
break(); case 1:
cout<<"Enter N:";
cin>>n; int *arr;
arr = randomNumberGen(n); break;
case 2: printArray(arr,n); break;
case 3:
heapSort(arr, n); break; case 4: sortDescending(arr,n);
 
break; case 5:
cout<<"\n"; int *arr1;
arr1=randomNumberGen(10000); clock_t start,end;
double total=0.0; start=clock(); heapSort(arr1, 10000); end=clock();
total+=(double)(end-start)/CLOCKS_PER_SEC;
cout<<"\nTime elapsed is %f seconds\n"<<total);
cout<<"Time Complexity=O(nlog n)\n\n"; break;
case 6:
cout<<"\n";
clock_t start1,end1; double total1=0.0; start1=clock(); heapSort(arr1, 10000); end1=clock();
total1+=(double)(end1-start1)/CLOCKS_PER_SEC; cout<<"\nTime elpased is %f seconds\n", total1; cout<<"Time Complexity=O(nlog n)\n";
break; case 7:
sortDescending(arr1,10000); clock_t start2,end2;
double total2=0.0; start2=clock(); heapSort(arr1, 10000); end2=clock();
total2+=(double)(end2-start2)/CLOCKS_PER_SEC; cout<<"\nTime elpased is %f seconds\n", total2); cout<<"Time Complexity=O(nlog n)\n";
 
break; case 8:
cout<<"Already Sorted: O(nlog n)\n"; cout<<"Reverse Sorted: O(nlog n)\n"; cout<<"Random Sample: O(nlog n)\n"; break;
case 9: largest(arr,n); break; case 10: replace(arr,n); break;
case 11:
cout<<"Enter the Element\n"; int key;
cin>>key; n=n+1; insert(arr,n,key); case 12:
n=n-1; delete(arr,n); break;
}
}while (choice!=0); return 0;
 

