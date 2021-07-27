#include <stdio.h>
struct student
{
  char name[50];
  long int id;
  long int phno;
} s[50];

int
main ()
{
  int n, i;
  char c;

  printf (" Enter no of students : ");
  scanf ("%d", &n);

  printf ("\n Enter information of students %d students :\n",n);

  // storing information
  for (i = 0; i < n; ++i)
    {
      
      printf ("Enter name : ");
      scanf ("%s", s[i].name);
      
      printf ("\nEnter id : ");
      scanf ("%ld",&s[i].id);
      
      printf ("\nEnter phone no : ");
      scanf ("%ld",&s[i].phno);
      
      printf("\n");
    }
    
    printf("\nDo you want to display the information? : ");
    scanf(" %c",&c);
    
    if(c=='y' || c=='Y')
     {
       printf ("Displaying Information:\n\n");

       // displaying information
         for (i = 0; i < n; ++i)
              {
      
                printf ("Name : %s",s[i].name);
      
                printf ("\n\nId : %ld", s[i].id);
      
                printf ("\n\nPhone No  : %ld", s[i].phno);
                 printf ("\n\n");
              }
              
     }
  return 0;
}
