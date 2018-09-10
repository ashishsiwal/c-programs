// deletenodeatanyposition.c
// program to delete node from any position from circular linked list
// source: https://www.w3resource.com/c-programming-exercises/linked_list/index.php

#include<stdio.h>
#include<stdlib.h>

typedef struct linkedlist
{
   int  data;
   struct linkedlist *next;
}cll;

cll *fnnode, *temp, *head;
int n;
void createlist(int n)
{
    for(int i=1; i<n; i++)
    {
        fnnode = (cll *)malloc(sizeof(cll));
        temp->next = fnnode;
        printf("\nEnter node %d data:", i);
        scanf("%d", &(fnnode->data));
        fnnode->next = NULL;
        temp = fnnode;         
    }
    temp->next = head;
}

void printlist(void)
{
    printf("\nList is:");
    do
    {
        printf("%d ",temp->data);
        temp = temp->next;
    } while(temp != head);
    printf("\n");
}

void deleteNodeAtAnyPosition(int position)
{
    for(int i=2; i<=position-1; i++)
    {
        temp = temp->next;
    }

    fnnode = (cll *)malloc(sizeof(cll));

    if(position == 1 || position == 0)
    {
        fnnode = head;
        while(temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = head->next;
        head = head->next;
        free(fnnode);
        fnnode = NULL;
    }

    else
    {
        fnnode = temp->next;
        temp->next = temp->next->next;
        free(fnnode);
        fnnode = NULL;
    }
    n--; //decreasing the number of nodes
}

// Driver program to test above functions
int main(void)
{
    int position;
    head = (cll *)malloc(sizeof(cll));
    head->next = NULL;

    printf("\nEnter the number of elements in the list:");
    scanf("%d", &n);

    if(n!=0)
    {
        printf("\nEnter node 0 data:");
        scanf("%d", &head->data);
    }

    else
    {
        printf("\nEnter a greater size please try again:(\n");
        return 1;
    }

    temp=head;
    createlist(n);
    temp = head; 
    printlist();

    printf("\nEnter the position(starts from 1 to %d) from which you want to delete node:",n);
    scanf("%d", &position);

    temp = head;
    deleteNodeAtAnyPosition(position);

    if(n!=0)
    {
        temp = head;
        printlist();
    }

    else
    {
        printf("\nError: nothing to print, list is empty\n");
        return 1;
    }
    
    return 0;
}