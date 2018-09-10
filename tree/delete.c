//source: https://ide.geeksforgeeks.org/4Dphc2OnbA
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
}tree;

tree *root, *fnnode, *temp;
int value;

void insert(tree **pointer)
{
    if(*pointer == NULL)
    {
        fnnode = (tree *)malloc(sizeof(tree));
        fnnode->data = value;
        fnnode->right = fnnode->left = NULL;
        *pointer = fnnode;
        return;
    }

    else if((*pointer)->data >= value)
    {
        insert(&(*pointer)->left);
    }

    else
    {
        insert(&(*pointer)->right);
    }
}

tree *minValueNode(tree *pointer)
{
    if(pointer->left == NULL)
    return pointer;

    minValueNode(pointer->left);
}

tree *delete(tree *pointer, int value)
{
    //base case
    if(pointer == NULL) return pointer;

    else if(value < pointer->data)
    pointer->left = delete(pointer->left, value);

    else if(value > pointer->data)
    pointer->right = delete(pointer->right, value);

    //if this is the pointer
    else
    {
        //right child or no child
        if(pointer->left == NULL)
        {
            temp = pointer->right;
            free(pointer);
            return temp;
        }

        //right child as null
        else if(pointer->right == NULL)
        {
            temp = pointer->left;
            free(pointer);
            return temp;
        }

        //if node has both right and left child
        temp = minValueNode(pointer->right);

        pointer->data = temp->data;

        pointer->right  = delete(pointer->right, temp->data);
    }
}

bool search(tree *pointer)
{
    if(pointer == NULL)
    return false;

    else if(pointer->data > value)
    search(pointer->left);

    else if(pointer->data < value)
    search(pointer->right);

    else
    return true;
}

void print(tree  *tree)
{
    if (tree != NULL)
    {
        printf("%d\n",tree->data);// pre order
        print(tree->left);
        //printf("%d\n",tree->data);// in order
        print(tree->right);

        //printf("%d\n",tree->data);// post order
    }
}

int main(void)
{
    root = (tree *)malloc(sizeof(tree));
    root->right = root->left =NULL;

    printf("\nEnter the root node data:");
    scanf("%d", &root->data);

    int option ;
    char choice = 'y';

    while( choice == 'y')
    {
        printf("Options:-\n1)Insert\n2)Delete\n3)Print\n");
        printf("\nChoose option:");
        scanf("%d", &option);

        switch( option )
        {
            case 1: 
            printf("\nEnter the value to insert into tree:");
            scanf("%d", &value);
            insert(&root);
            break;

            case 2:
            printf("\nEnter the value to delete:");
            scanf("%d", &value);

            if(root == NULL)
            printf("\nERROR: there is nothing to print in the tree, please insert something");

            else if(search(root) == false)
            {
                printf("\nERROR: Value not found in the tree, please try again:)");
            }
    
            else
            {
                printf("\n\nDeleting......\n");
                root = delete(root, value);
                printf("\nDeleted\n");
            }

            break; 

            case 3:
            if(root == NULL)
            {
                printf("\nERROR: tree is empty, nothing to print");
            }

            else
            {
                printf("\nprinting:\n");
                print(root);
            }
            break; 

            default:
            printf("\nERROR:enter the correct option:)");
            break;
        }
        printf("\n\nDo you want to choose options again?? (y/n):");
        scanf(" %c", &choice);
    }
}