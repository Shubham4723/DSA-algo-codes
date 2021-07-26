#include <stdio.h> 
#include <stdlib.h> 

struct node
{
    int data;
    struct node* left;
    struct node* right;
};
void findSiblings(struct node* rootPtr, int k)
{
    if (rootPtr == NULL)
        return;
    if (k == 0)
    {
        printf("%d ", rootPtr->data);
        return;
    }
    else
    {
        findSiblings(rootPtr->left, k - 1);
        findSiblings(rootPtr->right, k - 1);
    }
}

struct node* nNode(int data)
{
    struct node* n = (struct node*)
        malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return(n);
}

int main()
{

    struct node* r = nNode(1);
    r->left = nNode(2);
    r->right = nNode(3);
    r->left->left = nNode(4);
    r->left->right = nNode(5);
    r->right->left = nNode(8);
    int k;
    printf("Enter level = ");
    scanf("%d", &k);
    printf(" Siblings at kth level are = \n ");
    findSiblings(r, k);
    return 0;
}
