#include <stdio.h> 
#include <stdlib.h> 
void Sorting(int** ar, int ch);
int main()
{
    int m, n;
    printf("Enter m and n  = ");
    scanf("%d%d", &m, &n);

    int** a = (int**)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++)
        a[i] = (int*)malloc(n * sizeof(int));
    printf(" Input %d unique positive nos = ", m * n);
    for (int i = 0; i < m; i++) 
	{
    for (int j = 0; j < n; j++)
    {
    int t;
    scanf("%d", &t);
    if (t < 0)
    {
    printf(" You have entered a negative no. Please re enter a unique positive value. \n");
    j--;
    continue;
    }
    for (int y = 0; y <= i; y++) 
	{
    for (int z = 0; z <= m; z++)
    if (a[y][z] == t)
    {
    printf(" You have repeated a no. Please re enter a unique positive value.\n");
    j--;
    }
    break;

    }
    a[i][j] = t;
    }
    }

    printf(" The matrix is = \n ");
    for (int i = 0; i < m; i++) 
	{
    for (int j = 0; j < n; j++)
    printf("%d ", a[i][j]);
    printf("\n");
    }

    for (int i = 0; i < n; i++)
    Sorting(a, m);
    printf(" The matrix after sorting column wise is  = \n ");
    for (int i = 0; i < m; i++) 
	{
    for (int j = 0; j < n; j++)
    printf("%d ", a[i][j]);
    printf("\n");
    }
    float cc = 0;
    printf(" Enter %d elements to search in columns = ", n);
    for (int i = 0; i < n; i++)
    {
    int t;
    scanf("%d", &t);
    for (int y = 0; y < m; y++) {
    for (int z = 0; z < n; z++)
    if (a[y][z] == t)
    cc++;
    }
    }
    printf("Successful search = %f\n", cc / n);
    return 0;

}

void Sorting(int** ar, int ch)
{
    int k, h;
    int i, j;
    for (i = 0; i < ch; i++)
    {
        for (j = 1; j < ch; j++)
        {
            k = ar[j][i];
            h = j - 1;
            while (h >= 0 && ar[h][i] > k)
            {
                ar[h + 1][i] = ar[h][i];
                h--;
            }
            ar[h + 1][i] = k;
        }
    }
}
