#include <stdio.h> 
int N, M; 
  
void create(int Adj[][6], int arr[][2]) 
{ 
	int i,j;
    for (i=0;i<6;i++) { 
  
        for (j=0;j<6;j++) { 
            Adj[i][j] = 0; 
        } 
    } 

    for (i = 0; i < M; i++) { 

        int x = arr[i][0]; 
        int y = arr[i][1]; 

        Adj[x][y] = 1; 
        Adj[y][x] = 1; 
    } 
} 

int print(int Adj[][5]) 
{ 
	int i,j;
    for ( i=1;i<6;i++) 
	{ 
		printf("%d\t",i);
        for (j=1;j<6;j++) { 

            printf("%d ", Adj[i][j]); 
        } 
        printf("\n"); 
    } 
    return 0;
} 

int main() 
{ 

    int arr[][2] 
        = { { 1, 2 }, { 2, 3 },  
            { 4, 5 }, { 1, 5 } }; 
            
    M = sizeof(arr) / sizeof(arr[0]); 
    int Adj[6][6]; 

    create(Adj, arr); 
    print(Adj); 
  
    return 0; 
}
