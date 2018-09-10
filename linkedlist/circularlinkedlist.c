// circularlinkedlist.c
// program to create a circular linked list
//source: https://www.w3resource.com/c-programming-exercises/linked_list/index.php

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

void printlist()
{
    printf("\nList is:");
    do
    {
        printf("%d ",temp->data);
        temp = temp->next;
    } while(temp != head);
    printf("\n");
}

// Driver program to test above functions
int main(void)
{
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
    printlist(n);
}