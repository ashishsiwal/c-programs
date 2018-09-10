//Program to search a single linked list
//source: https://www.w3resource.com/c-programming-exercises/linked_list/index.php
#include<stdio.h>
#include<stdlib.h>

typedef struct linkedlist
{
   int  data;
   struct linkedlist *next;
}ll;

ll *fnnode, *temp, *head;
int n;
void createlist(int n)
{
    for(int i=1; i<n; i++)
    {
        fnnode = (ll *)malloc(sizeof(ll));
        temp->next = fnnode;
        printf("\nEnter node %d data:", i);
        scanf("%d", &(fnnode->data));
        fnnode->next = NULL;
        temp = fnnode;         
    }
}

void printlist()
{
    printf("\nList is:");
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int searchElement(int x)
{
    for(int i=0; i<n ;i++)
    {
        if(temp->data == x)
        {
            printf("\nElement found at node: %d\n",i);
            return 0;
        }
        temp = temp->next;
    }
    printf("\nError: Element not found\n");
}

// Driver program to test above functions
int main(void)
{
    head = (ll *)malloc(sizeof(ll));
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

    int x;
    printf("\nEnter the element you want to search:");
    scanf("%d", &x);

    temp = head;
    searchElement(x);

    return 0;
}