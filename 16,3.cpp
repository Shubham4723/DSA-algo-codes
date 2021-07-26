#include <stdio.h>
int main()
{
  int container[100], hunt, c, n;

  printf("Enter number of elements in array\n");
  scanf("%d", &n);

  printf("Enter %d integer(s)\n", n);

  for (c = 0; c < n; c++)
    scanf("%d", &container[c]);

  printf("Enter a number to search\n");
  scanf("%d", &hunt);

  for (c = 0; c < n; c++)
  {
    if (container[c] == hunt)  
    {
      hunt=3*hunt;
    }
  }
  if (c == n)
    printf("Output is %d\n", hunt);

  return 0;
}
