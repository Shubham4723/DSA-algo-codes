#include <stdio.h>
int main()
{
  int a[100], s, k, m;

  printf("Enter number of elements in array\n");
  scanf("%d", &m);

  printf("Enter %d integer(s)\n", m);

  for (k = 0; k< m; k++)
    scanf("%d", &a[k]);

  printf("Enter a number to search\n");
  scanf("%d", &s);

  for (k = 0; k < m; k++)
  {
    if (a[k] == s)  
    {
      printf("%d is present at location %d.\n", s, k+1);
      break;
    }
  }
  if (k == m)
    printf("%d isn't present in the array.\n", s);

  return 0;
}
