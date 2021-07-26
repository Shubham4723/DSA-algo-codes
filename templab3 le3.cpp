#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX1 3
#define MAX2 3

struct cheadnode
{
    int colno ;
    struct node *down ;
    struct cheadnode *next ;
} ;

struct rheadnode
{
    int rowno ;
    struct node * right ;
    struct rheadnode *next ;
} ;

struct node
{
    int row ;
    int col ;
    int val ;
    struct node *right ;
    struct node *down ;
} ;
struct spmat
{
    struct rheadnode *firstrow ;
    struct cheadnode *firstcol ;
    int noofrows ;
    int noofcols ;
} ;

struct sparse
{
    int *sp ;
    int row  ;
    struct spmat *smat ;
    struct cheadnode *chead[MAX2] ;
    struct rheadnode *rhead[MAX1] ;
    struct node *nd ;
} ;

void initsparse ( struct sparse * ) ;
void create_array ( struct sparse * ) ;
void display ( struct sparse ) ;
int count ( struct sparse ) ;
void create_triplet ( struct sparse *, struct sparse ) ;
void create_llist ( struct sparse * ) ;
void insert ( struct sparse *, struct spmat *, int, int, int ) ;
void show_llist ( struct sparse ) ;
void delsparse ( struct sparse * ) ;

int main( )
{
    struct sparse s1, s2 ;

    

    initsparse ( &s1 ) ;
    initsparse ( &s2 ) ;

    create_array ( &s1 ) ;

    printf ( "\nElements in sparse matrix: " ) ;
    display ( s1 ) ;

    create_triplet ( &s2, s1 ) ;

    create_llist ( &s2 ) ;
    printf ( "\n\nInformation stored in linked list : " ) ;
    show_llist ( s2 ) ;

    delsparse ( &s1 ) ;
    delsparse ( &s2 ) ;

    getch( ) ;
}

void initsparse ( struct sparse *p )
{
    int i ;

for ( i = 0 ; i < MAX1 ; i++ )
        p -> rhead[i] = ( struct rheadnode * ) malloc ( sizeof ( struct rheadnode ) ) ;

for ( i = 0 ; i < MAX1 - 1 ; i++ )
    {
        p -> rhead[i] -> next = p -> rhead[i + 1] ;
        p -> rhead[i] -> right = NULL ;
        p -> rhead[i] -> rowno = i ;
    }
    p -> rhead[i] -> right = NULL ;
    p -> rhead[i] -> next = NULL ;

for ( i = 0 ; i < MAX1 ; i++ )
        p -> chead[i] = ( struct cheadnode * ) malloc ( sizeof ( struct cheadnode ) ) ;

for ( i = 0 ; i < MAX2 - 1 ; i++ )
    {
        p -> chead[i] -> next = p -> chead[i + 1] ;
        p -> chead[i] -> down = NULL ;
        p -> chead[i] -> colno = i ;
    }
    p -> chead[i] -> down = NULL ;
    p -> chead[i] -> next = NULL ;

    p -> smat = ( struct spmat * ) malloc ( sizeof ( struct spmat ) ) ;
    p -> smat -> firstcol = p -> chead[0] ;
    p -> smat -> firstrow = p -> rhead[0] ;
    p -> smat -> noofcols = MAX2 ;
    p -> smat -> noofrows = MAX1 ;
}

void create_array ( struct sparse *p )
{
    int n, i ;

    p -> sp = ( int * ) malloc ( MAX1 * MAX2 * sizeof ( int ) ) ;

for ( i = 0 ; i < MAX1 * MAX2 ; i++ )
    {
        printf ( "Enter element no. %d:", i ) ;
        scanf ( "%d", &n ) ;
        * ( p -> sp + i ) = n ;
    }
}

void display ( struct sparse s )
{
    int i ;

for ( i = 0 ; i < MAX1 * MAX2 ; i++ )
    {
if ( i % MAX2 == 0 )
            printf ( "\n" ) ;
        printf ( "%d\t", * ( s.sp + i ) ) ;
    }
}

int count ( struct sparse s )
{
    int cnt = 0, i ;

    for ( i = 0 ; i < MAX1 * MAX2 ; i++ )
    {
        if ( * ( s.sp + i ) != 0 )
            cnt++ ;
    }
    return cnt ;
}

void create_triplet ( struct sparse *p, struct sparse s )
{
    int r = 0 , c = -1, l = -1, i ;

    p -> row = count ( s ) ;
    p -> sp = ( int * ) malloc ( p -> row * 3 * sizeof ( int ) ) ;

    for ( i = 0 ; i < MAX1 * MAX2 ; i++ )
    {
        c++ ;
if ( ( ( i % MAX2 ) == 0 ) && ( i != 0 ) )
        {
            r++ ;
            c = 0 ;
        }

if ( * ( s.sp + i ) != 0 )
        {
            l++ ;
            * ( p -> sp + l ) = r ;
            l++ ;
            * ( p -> sp + l ) = c ;
            l++ ;
            * ( p -> sp + l ) = * ( s.sp + i ) ;
        }
    }
}

void create_llist ( struct sparse *p )
{
    int j = 0, i ;
    for ( i = 0 ; i < p -> row ; i++, j+= 3 )
        insert ( p, p -> smat, * ( p -> sp + j ), * ( p -> sp + j + 1 ),
                                                * ( p -> sp + j + 2) ) ;
}

void insert ( struct sparse *p, struct spmat *smat , int r, int c, int v )
{
    struct node *temp1, *temp2 ;
    struct rheadnode *rh ;
    struct cheadnode *ch ;
    int i, j ;

    p -> nd = ( struct node * ) malloc ( sizeof ( struct node ) ) ;
    p -> nd -> col = c ;
    p -> nd -> row = r ;
    p -> nd -> val = v ;

rh = smat -> firstrow ;

for ( i = 0 ; i < r ; i++ )
        rh = rh -> next ;
    temp1 = rh -> right ;

if ( temp1 == NULL )
    {
        rh -> right = p -> nd ;
        p -> nd -> right = NULL ;
    }
    else
    {
while ( ( temp1 != NULL  ) && ( temp1 -> col < c ) )
        {
            temp2 = temp1 ;
            temp1 = temp1 -> right ;
        }
        temp2 -> right = p -> nd ;
        p -> nd -> right = NULL ;
    }
 ch = p -> smat -> firstcol ;
    for ( j = 0 ; j < c ; j++ )
        ch = ch -> next ;
    temp1 = ch -> down ;

if ( temp1 == NULL )
    {
        ch -> down = p -> nd ;
        p -> nd -> down = NULL ;
    }
    else
    {
while ( ( temp1 != NULL ) && ( temp1 -> row < r ) )
        {
            temp2 = temp1 ;
            temp1 = temp1 -> down ;
        }
        temp2 -> down = p -> nd ;
        p -> nd -> down = NULL ;
    }
}

void show_llist ( struct sparse s )
{
    struct node *temp ;
int r = s.smat -> noofrows ;
    int i ;

    printf ( "\n" ) ;

    for ( i = 0 ; i < r ; i++ )
    {
        temp = s.rhead[i] -> right ;
        if ( temp != NULL )
        {
            while ( temp -> right != NULL )
            {
                printf ( "Row: %d Col: %d Val: %d\n", temp -> row, temp -> col,
                                                        temp -> val ) ;
                temp = temp -> right ;
            }
            if ( temp -> row == i )
                printf ( "Row: %d Col: %d Val: %d\n", temp -> row, temp -> col,
                                                    temp -> val ) ;
        }
    }
}

void delsparse ( struct sparse *p )
{
    int r = p -> smat -> noofrows ;
       struct rheadnode *rh ;
    struct node *temp1, *temp2 ;
    int i, c ;

for ( i = r - 1 ; i >= 0 ; i-- )
    {
        rh = p -> rhead[i] ;
        temp1 = rh -> right ;

        while ( temp1 != NULL )
        {
            temp2 = temp1 -> right ;
            free ( temp1 ) ;
            temp1 = temp2 ;
        }
    }
    c = p -> smat -> noofcols ;
    for ( i = c - 1 ; i >= 0 ; i-- )
        free ( p -> chead[i] ) ;
}
