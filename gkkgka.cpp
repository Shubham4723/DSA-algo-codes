#include<stdio.h>
#include <stdio.h>
#include <stdlib.h>
 
struct node {
    int key;
    struct node *left, *right;
};
struct node* newNode(int item)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
struct node* insert(struct node* node, int key)
{
   
    if (node == NULL)
        return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}

void inorder(struct node* root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}
 
 void preorder(struct node* root)
{
    if (root != NULL) {
    	printf("%d \n", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}
 
 void postorder(struct node* root)
{
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d \n", root->key);
    }
}
 
int search(struct node* root,int item)
{
	if(!root) return -1;
	if(root->key == item)
		return 1;
	else if(root->key > item)
		return search(root->left,item);
	else
		return search(root->right,item);
return -1;
}
 
int minValue(struct node* node)  
{  
struct node* current = node;  
while (current->left != NULL)  
{  
    current = current->left;  
}  
return(current->key);  
} 

int maxValue(struct node* node)  
{  
struct node* current = node;  
while (current->right != NULL)  
{  
    current = current->right;  
}  
return(current->key);  
} 


 int max_node_val(struct node* root)
    {
            if(root->right!= NULL) {
                    return max_node_val(root->right);
            }
            else
            {
                    return root->key;
            }
    }
  struct node* deleteNode(struct node* root, int key) {
            if(!root) return NULL;
           else if(key > root->key)
            {
                    root->right = deleteNode(root->right,key);
            }
           else if(key < root->key)
            {
                    root->left = deleteNode(root->left,key);
            }
            else
            {
                    if(root->left!= NULL && root->right != NULL)
                    {
                            int lmax = max_node_val(root->left);
                            root->key = lmax;
                            root->left = deleteNode(root->left,lmax);
                            return root;
                    }
                    else if(root->left == NULL)
                    {
                            return root->right;
                    }
                    else if(root->right == NULL)
                    {
                            return root->left;
                    }
                    else
                    {
                            return NULL;
                    }
            }
         return root; 
    }



int main()
{
    struct node* root = NULL;
    int ch,n,data;
    while (1)
{
printf("\n1.Insertion in Binary Search Tree");
printf("\n2.Search Element in Binary Search Tree");
printf("\n3.Delete Element in Binary Search Tree");
printf("\n4.Find smallest element in Binary Search Tree");
printf("\n5.Find largest element in Binary Search Tree");
printf("\n6.Inorder\n7.Preorder\n8.Postorder\n9.Exit");
printf("\nEnter your choice: ");
scanf("%d", &ch);
switch (ch)
{
case 1: 
printf("\nEnter  value: " );
scanf("%d", &data);
root = insert(root, data);
break;
case 2:
 printf("\nEnter the element to search: ");
scanf("%d", &data);
if (search(root, data) == -1)
printf("Value not found\n");
else
	printf("value found\n");
break;
case 3: printf("\nEnter the element to delete: ");
scanf("%d", &data);
root = deleteNode(root, data);
break;
case 4:
printf("%d",minValue(root));
break;
case 5:
printf("%d",maxValue(root));
break;
case 6: printf("\nInorder Traversal: \n");
inorder(root);
break;
case 7: printf("\nPreorder Traversal: \n");
preorder(root);
break;
case 8: printf("\nPostorder Traversal: \n");
postorder(root);
break;
case 9: exit(0);
default:printf("\nWrong option");
break;
}
}
}
