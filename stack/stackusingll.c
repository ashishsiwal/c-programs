#include<stdio.h>
#include<stdlib.h>

typedef struct stackusingll
{
    int data;
    struct stackusingll *next;
}sull;

sull *head = NULL, *temp, *fnnode;

void push(int value)
{
    printf("\n\nPushing.......\n");

    fnnode = (sull *)malloc(sizeof(sull));

    if ( fnnode == NULL )
    {
        printf("\n\nERROR: Heap Overflow");
        return;
    }
    fnnode->data = value;
    fnnode->next = head;
    head = fnnode;

    printf("\nPushed\n");
}

void pop()
{
    printf("\n\nPopping.......\n");

    if ( head == NULL )
    {
        printf("\nERROR: stack is empty, nothing to pop");
        return;
    }
    temp = head; 
    head = head->next;
    free(temp);
    temp = NULL;

    printf("\nPopped\n");
}

void isEmpty()
{
    printf("\n\nChecking......\n");

    if ( head == NULL )
    printf("\nstack is empty");

    else
    printf("\nstack is not empty");
}

void print(struct stackusingll  *temp)
{
    if (head ==NULL)
    {
        printf("\nERROR: stack is empty, nothing to print");
        return;
    }

    while(temp !=NULL)
    {
        printf("\n%d", temp->data);
        temp = temp->next;
    }
}

int main(void)
{
    int option, value;
    char choice = 'y';

    while( choice == 'y')
    {
        printf("Options:-\n1)Push\n2)Pop\n3)isEmpty\n4)Print\n");
        printf("\nChoose option:");
        scanf("%d", &option);

        switch( option )
        {
            case 1: 
            printf("\nEnter the value to push onto satck:");
            scanf("%d", &value);
            push(value);
            break;

            case 2:
            pop();
            break;

            case 3:
            isEmpty();
            break;

            case 4:
            printf("\n\nPrinting.....\nStack is:-\n");
            print(head);
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