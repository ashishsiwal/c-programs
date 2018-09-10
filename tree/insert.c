#include<stdio.h>
#include<stdlib.h>

typedef struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
}tree;

tree *fnnode, *root;

int value;

//Queue as a linked list
typedef struct queue
{
    tree *address;
    struct queue *next;
}queue;

queue *head , *temp, *rear, *qnode;

//Function to insert a value
void insert(tree *pointer)
{
    if(pointer == NULL)
    {
        fnnode = (tree *)malloc(sizeof(tree));
        fnnode->data = value;
        fnnode->right = NULL;
        fnnode->left = NULL;
        pointer = fnnode;
        return;
    }

    else if(value <= (pointer)->data)
    insert((pointer)->left); //(*pointer)->left this will work too.

    else
    insert((pointer)->right);
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

//Driver function to check above functions
int main(void)
{
    root = (tree *)malloc(sizeof(tree));
    printf("\nEnter the root node data:");
    scanf("%d", &root->data);

    root->right = NULL;
    root->left = NULL;

    head = (queue *)malloc(sizeof(queue));
    head->address = root;
    head->next = NULL;

    int option ;
    char choice = 'y';

    while( choice == 'y')
    {
        printf("\noptions:\n1)Insert\n2)Print\n");
        printf("Choose option:");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
            printf("\nEnter the value to insert:");
            scanf("%d", &value);
            insert(root);
            break;

            case 2:
            printf("\n\nLevel Order(from left to right) Printing......\n");
            print(root);
            break;

            default:
            printf("\nERROR:enter the correct option:)");
            break;
        }
        printf("\n\nDo you want to choose options again?? (y/n):");
        scanf(" %c", &choice);
    }
    return 0;
}

