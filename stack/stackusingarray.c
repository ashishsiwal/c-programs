#include<stdio.h>
#include<stdlib.h>
#define SIZE 3
int top = -1; 
int stack[SIZE];

void push( int value)
{
    printf("\n\nPushing.......\n");
    if(top == SIZE-1)
    {
        printf("\nStack Overflow!!!");
        top--;
        return;
    }

    stack[++top] = value;
    printf("\nPushed\n");
}

void pop()
{
    printf("\n\nPopping.......\n");
    if( top < 0)
    {
        printf("\nStack is empty");
        return;
    }
    top--;
    printf("\nPopped\n");
}

void isEmpty()
{
    printf("\n\nChecking......\n");
    if ( top < 0 )
    {
        printf("\nStack is empty");
    }
    else
    printf("\nStack is not empty");
}

void print()
{
    printf("\n\nPrinting.....\nStack is:-\n");
    if( top < 0 )
    {
        printf("\nstack is empty cannot be printed");
        return;
    }
    for(int i=0; i<=top; i++)
    printf("\n%d", stack[top-i]);
}

//Driver function to check above functions

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
            print();
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