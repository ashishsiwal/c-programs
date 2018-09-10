#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
#define MAX(x, y) (((x) > (y)) ? (x) : (y)) //just a function to find max of 2 nos.

//tree structure
typedef struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
}tree;

tree *fnnode, *root, *temp;

int value;

int a = 0, b = 0, x, y;

//functions
void insert(tree **pointer);
void delete(tree **pointer, int value);
void print(tree  *tree);
bool search(tree *pointer);
int  minimum(tree *pointer);
int  maximum(tree *pointer);
int maxHeight(tree *pointer);

// 1st Function to insert a value
void insert(tree **pointer) //"** " used so that pointer doesn't become local variable
{
    if(*pointer == NULL)
    {
        fnnode = (tree *)malloc(sizeof(tree));
        fnnode->data = value;
        fnnode->right = NULL;
        fnnode->left = NULL;
        *pointer = fnnode;
        return;
    }

    else if(value <= (*pointer)->data)
    insert(&(**pointer).left); //(*pointer)->left this will work too.

    else
    insert(&(*pointer)->right);
}


// 2nd Function to delete node
void delete(tree **pointer, int value)
{
    if((*pointer)->data == value && (*pointer)->right != NULL)
    {
        int min = minimum((*pointer)->right);
        (*pointer)->data = min;
        delete(&(*pointer)->right, min);
    }

    else if((*pointer)->data == value && (*pointer)->left != NULL)
    {
        temp = (*pointer);
        (*pointer)  = (*pointer)->left;
        free((temp));
        temp = NULL;
        return;
    }

    else if((*pointer)->data == value )
    {
        free((*pointer));
        *pointer = NULL;
        return;
    }


    else if(value < (*pointer)->data && (*pointer)->left != NULL && (*pointer)->left->data != value)
    delete(&(*pointer)->left, value);

    else if(value > (*pointer)->data && (*pointer)->right != NULL && (*pointer)->right->data != value)
    delete(&(*pointer)->right, value);


    else if((*pointer)->right != NULL && (*pointer)->right->data == value)
    {
        if((*pointer)->right->right != NULL)
        {
            int i = minimum((*pointer)->right->right);
            (*pointer)->right->data = i;
            delete(&(*pointer)->right->right, i);
        }

        else if((*pointer)->right->left != NULL)
        {
            temp = (*pointer)->right;
            (*pointer)->right = (*pointer)->right->left;
            free(temp);
            temp = NULL;
            return;
        }

        else //(pointer->left->left == NULL && pointer->left->right == NULL)
        {
            temp = (*pointer)->right;
            (*pointer)->right = NULL;
            free(temp);
            temp = NULL;
            return;
        }

    }

    else if((*pointer)->left != NULL && (*pointer)->left->data == value)
    {
        if((*pointer)->left->right != NULL)
        {
            int i = minimum((*pointer)->left->right);
            (*pointer)->left->data = i;
            delete(&(*pointer)->left->right, i);
            return;
        }

        else if((*pointer)->left->left != NULL)
        {
            temp = (*pointer)->left;
            (*pointer)->left = (*pointer)->left->left;
            free(temp);
            temp = NULL;
            return;
        }

        else //(pointer->left->left == NULL && pointer->left->right == NULL)
        {
            temp = (*pointer)->left;
            (*pointer)->left = NULL;
            free(temp);
            temp = NULL;
            return;
        }
    }
}

// 3rd Function to print tree
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

// 4th Function to seach a node in tree
bool search(tree *pointer)
{
    if(pointer == NULL)
    {
        printf("\nNot found\n");
        return false;
    }

    else if(value == pointer->data)
    {
        printf("\nFound!!!\n");
        return true;
    }

    else if(value < pointer->data)
    search(pointer->left);

    else
    search(pointer->right);
}

// 5th Function for minimum value
int  minimum(tree *pointer)
{
    if(pointer->left == NULL)
    {
        return pointer->data;
    }

    minimum(pointer->left);
}

// 5th Function for maximum value
int maximum(tree *pointer)
{
    if(pointer->right == NULL)
    {
        return pointer->data;
    }

    maximum(pointer->right);
}


// 6th Function to return the height of tree
int maxHeight(tree *pointer)
{
    if(pointer == NULL)
    return -1;

    int a = maxHeight(pointer->left);
    
    int b = maxHeight(pointer->right);
    
    return MAX(a,b) + 1;
}

//Driver function to test above function
int main(void)
{
    root = (tree *)malloc(sizeof(tree));
    printf("\nEnter the root node data:");
    scanf("%d", &root->data);

    root->right = NULL;
    root->left = NULL;

    int option ;
    char choice = 'y';

    while( choice == 'y')
    {
        printf("Options:-\n1)Insert\n2)Delete\n3)Print\n4)Search\n5)Minimum & Maximum value\n6)Height\n");
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
                delete(&root, value);
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

            case 4:
            printf("\nEnter the value to be searched:");
            scanf("%d", &value);
            if(root == NULL)
            printf("\nERROR: tree is empty, nothing to search:)");

            else
            search(root);
            break;  

            case 5:
            if(root ==NULL)
            {
                printf("\nERROR: tree is empty, nothing to find:)");
            }
            else
            {
                x = minimum(root);
                printf("\nMinimum value: %d\n", x);

                y = maximum(root);
                printf("\nMaximum value: %d\n", y);
            }
            break;

            case 6:
            printf("\nHeight: %d\n", maxHeight(root));
            break;

            default:
            printf("\nERROR:enter the correct option:)");
            break;
        }
        printf("\n\nDo you want to choose options again?? (y/n):");
        scanf(" %c", &choice);
    }
}