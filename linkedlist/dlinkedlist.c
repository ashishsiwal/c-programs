//Program for creating a doubly linked list
//source: https://www.w3resource.com/c-programming-exercises/linked_list/index.php

#include<stdio.h>
#include<stdlib.h>

typedef struct dlinkedlist
{
    struct dlinkedlist *prev; //previous
    int data;
    struct dlinkedlist *next;
} dll;

dll *fnnoode, *temp, *head; //pointers to linked list

int n; //size of linked list

void createDLinkedlist(void)
{
    for(int i=1; i<n; i++)
    {
        fnnoode = (dll *)malloc(sizeof(dll));
        fnnoode->prev = temp;
        temp->next = fnnoode;

        printf("\nEnter node %d data:",i);
        scanf("%d", &fnnoode->data);

        fnnoode->next = NULL;
        temp = fnnoode;
    }
}

void printDLinkedlist(void)
{
    printf("\nThe list is:");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

//Driver function to test above functions
int main(void)
{
    printf("\nEnter the size of double linked list:");
    scanf("%d", &n);

    head = (dll *)malloc(sizeof(dll));
    head->prev = NULL;
    head->next = NULL;

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

    temp = head;
    createDLinkedlist();

    temp = head;
    printDLinkedlist();

    return 0;
}