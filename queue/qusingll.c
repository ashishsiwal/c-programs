#include<stdio.h>
#include<stdlib.h>

typedef struct qusingll
{
    int data;
    struct qusingll *next;
}qull;

qull *front = NULL, *rear = NULL, *temp, *fnnode;

void enqueue(int value)
{
    printf("\n\nEnqueuing.......\n");
    fnnode = (qull *)malloc(sizeof(qull));

    if(fnnode == NULL)
    {
        printf("\nERROR: Queue Overflow");
        return;
    }

    fnnode->data = value;
    fnnode->next = NULL;

    if ( front == NULL || rear == NULL )
    {
        front = fnnode;
        rear = fnnode;
    }

    else
    {
        rear->next = fnnode;
        rear = fnnode;
    }
    printf("\nEnqueued........\n");
}

void dequeue(void)
{
    if(front == NULL)
    {
        printf("\nERROR: queue is empty");
        return;
    }
    printf("\n\nDequeuing.......\n");
    temp = front;

    if(front == rear)
    {
        front = NULL;
        rear = NULL;
    }

    else front = front->next; // to save us from seg fault
    free(temp);
    temp = NULL;
    printf("\n\nDequeued.......\n");
}

void isEmpty(void)
{
    printf("\n\nChecking......\n");
    if(front == NULL || rear == NULL)
    printf("\nQueue is empty");
    else
    printf("\nQueue is not empty");
}

void print(void)
{
    if(front == NULL)
    {
        printf("\nERROR: queue is empty, nothing to print");
        return;
    }
    printf("\n\nPrinting.....\nQueue is: ");
    temp = front;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
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

