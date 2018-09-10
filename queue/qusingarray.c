#include<stdio.h>
#define SIZE 100


int front = -1, rear = -1, queue[SIZE];

//push
void enqueue(int value)
{
    printf("\n\nEnqueuing.......\n");
    if(rear == SIZE-1)
    {
        printf("\nERROR: Queue Overflow");
        return;
    }

    else if(front == -1)
    {
        front = 0;
    }

    queue[++rear] = value;
    printf("\nEnqueued........\n", front, rear);
}

//pop
void dequeue(void)
{
    printf("\n\nDequeuing.......\n");
    if(rear == -1 && front == -1)
    {
        printf("\nERROR: queue is empty");
        return;
    }

    else if(front == rear)
    {
        front = -1;
        rear = -1;
    }

    else
    front++ ;
    printf("\n\nDequeued.......\n", front, rear);
}

void isEmpty(void)
{
    printf("\n\nChecking......\n");
    if(front == -1 && rear == -1)
    {
        printf("\nQueue is empty");
    }

    else
    printf("\nQueue is not empty");
}

void print(void)
{
    printf("\n\nPrinting.....\nQueue is: ");
    if(front == -1 && rear == -1)
    {
        printf("\nERROR: queue is empty, nothing to print");
        return;
    }

    for(int i=rear; i>= front; i--)
    {
        printf("%d ", queue[i]);
    }
}

int main(void)
{
    int option, value;
    char choice = 'y';

    while( choice == 'y')
    {
        printf("Options:-\n1)Enqueue\n2)Dequeue\n3)isEmpty\n4)Print\n");
        printf("\nChoose option:");
        scanf("%d", &option);

        switch( option )
        {
            case 1: 
            printf("\nEnter the value to push into queue:");
            scanf("%d", &value);
            enqueue(value);
            break;

            case 2:
            dequeue();
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

