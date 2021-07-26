#include <iostream>
#include<math.h>
#include<cstdlib>
using namespace std;

void heapify(int arr[], int n, int i) { 
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    
    if (l < n && arr[l] < arr[smallest]) 
        smallest = l; 

    if (r < n && arr[r] < arr[smallest]) 
        smallest = r; 

    if (smallest != i) { 
        swap(arr[i], arr[smallest]); 

        heapify(arr, n, smallest); 
    } 
} 

void heapSort(int arr[], int n) { 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]); 
        heapify(arr, i, 0); 
    } 
}

int partition(int A[], int p, int r) {
    int x = A[p];
    int i = p;
    int j = r;

while(true) {

 while (A[i] < x) {
        i++;
 }

 while (A[j] > x) {
        j--;
 }

    if (i < j) {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
        i++;
        j--;
    } else {
        return j;
        }
    }
}

void quicksort(int A[], int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quicksort(A, p, q);
        quicksort(A, q + 1, r);
    }
}; 

void delete1(int *arr,int n) { 
    int last = arr[n - 1]; 
    arr[0] = last;
}
void insert(int *arr,int n,int key) { 
    arr[n-1] = key;
} 
void replace(int *arr,int n) {
    int k,in;
    printf("Enter Element and Index of Replacement:\n");
    scanf("%d%d",&k,&in);
    arr[in]=k;
}

int main() {
	// your code goes here
	int op;
	cout << "Enter the operation to be performed: " << endl;
	cout << "0. Quit" << endl;
	cout << "1. n Random number" << endl;
	cout << "2. Display the array" << endl;
	cout << "3. Sort the array in descending order by using min heap sort algorithm!!" << endl;
	cout << "4. Sort the array in ascending order by any algorithm!!" << endl;
	cout << "5. Time complexity to sort descending of random data!!" << endl;
	cout << "6. Time complexity to sort descending of data already sorted in ascending order!!" << endl;
	cout << "7. Time complexity to sort descending of data already sorted in descing order!!" << endl;
	cout << "8. Time complexity to sort descending all cases" << endl;
	cout << "9. Extract largest element!!" << endl;
	cout << "10. Replace value at a node with new node!!" << endl;
	cout << "11. Insert a new element!!" << endl;
	cout << "12. delete a element!!" << endl;
	cin >> op;
	
	int n;
	cin >> n; 
	int array[n];
	int lar = array[0];
	
	switch(op) {
	    case 0: 
	        exit(1);
	        break;
	    case 1:
	        for(int i = 0; i < n; i++)
	            array[i] = rand() % 100;
	        break;
	    case 2: 
	        for(int i = 0; i < n; i++) 
	            cout << array[i] << " ";
	        break;
	    case 3: 
	        heapSort(array, n);
	        for(int i = 0; i < n; i++) 
	            cout << array[i] << " ";
	        break;
	    case 4:
	        quicksort(array, 0, n-1);
	        for(int i = 0; i < n; i++) 
	            cout << array[i] << " ";
	        break;
	    case 5:
	        cout << "O(nlogn)" << endl;
	        break;
	    case 6: 
	        cout << "O(nlogn)" << endl;
	        break;
	    case 7:
	        cout << "O(nlogn)" << endl;
	        break;
	    case 8: 
	        cout << "Time complexity in all cases: " << endl;
	        cout << "------------------------------------------" << endl;
	        cout << "Data in ascending        :        O(nlogn)" << endl;
	        cout << "Data in descending       :        O(nlogn)" << endl;
	        cout << "Data in random           :        O(nlogn)" << endl;
	        break;
	    case 9: 
	        for(int i = 1; i < n; i++) {
	            if(lar < array[i]) {
	                lar = array[i];
	            }
	        }
	        cout << "Largest element in array: " << lar << endl;
	        break;
	    case 10:
	        replace(array, n);
	        break;
	    case 11:
	        printf("Enter the Element\n");
            int key;
            scanf("%d",&key);
            n=n+1;
            insert(array,n,key);
	        break;
	    case 12:
	        n=n-1;
            delete1(array, n);
	        break;
	    default:
	        cout << "Invalid operation!!" << endl;
	        break;
	}
	return 0;
}
