// Program to add a new element at the starting, middle and the last position of the linked
// -list
//source: https://www.w3resource.com/c-programming-exercises/linked_list/index.php

#include<stdio.h>
#include<stdlib.h>

typedef struct linkedlist
{
    int data;
    struct linkedlist *next;
} ll;

int n; // size of linked list

ll *fnnode, *temp, *head;

void creatingList(int n)
{
    for(int i=1; i<n; i++)
    {
        fnnode = (ll *)malloc(sizeof(ll));
        printf("\nEnter node %d data:",i);
        scanf("%d", &fnnode->data);

        temp->next = fnnode;
        fnnode->next = NULL;
        temp = fnnode;
    }
}

void printlist(void)
{
    printf("\nList is:");
    while(temp != 0)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void elementAtStart(void)
{
    fnnode = (ll *)malloc(sizeof(ll));
    printf("\nEnter the element to add at the starting:");
    scanf("%d", &fnnode->data);
    fnnode->next = head;
    head = fnnode;
    n++; //increasing the number of elements in linked list
}

void elementInMiddle(int n)
{
    for(int i=0; i < (n-2)/2; i++) temp = temp->next;

    fnnode = (ll *)malloc(sizeof(ll));
    printf("\nEnter the element to add at the middle:");
    scanf("%d", &fnnode->data);
    fnnode->next = temp->next;
    temp->next = fnnode;
}

void elementAtLast(int n)
{
    for(int i=0; i<n-1; i++) temp = temp->next;

    fnnode = (ll*)malloc(sizeof(ll));
    printf("\nEnter the element to add at the last:");
    scanf("%d", &fnnode->data);
    
    temp->next = fnnode; 
    fnnode->next = NULL;
    n++; //increasing the number of elements in linked list
}

//Driver program to check above functions
int main(void)
{
    head = (ll *)malloc(sizeof(ll));
    head->next = NULL;

    printf("\nEnter the size of linked list:");
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

    temp = head;
    creatingList(n);

    temp = head;
    printlist();

    elementAtStart();

    temp = head;
    printlist();

    temp = head;
    elementInMiddle(n);

    temp = head;
    printlist(); 

    temp = head;
    elementAtLast(n);

    temp = head;
    printlist();

    return 0;
}