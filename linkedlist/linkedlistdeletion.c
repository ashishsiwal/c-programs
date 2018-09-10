// Program to delete node from linked list
//source: https://www.w3resource.com/c-programming-exercises/linked_list/index.php
#include<stdio.h>
#include<malloc.h>

typedef struct linkedlist{
    int data;
    struct linkedlist *next;
}ll;
 ll *temp, *fnnode, *head, *nnode;
 int n;

//creating linked list
void creatinglist(int n)
{
    for(int i=1; i<n; i++)
    {
        fnnode=(ll *)malloc(sizeof(ll));
        printf("\nEnter %d node data:",i);
        scanf("%d",&fnnode->data);
        temp->next=fnnode;
        fnnode->next=NULL;
        temp=temp->next;
    }
}

//printing function
void printlist(int n)
{
    while(temp!=NULL)
    {
        printf("\n%d",temp->data);
        temp=temp->next;
    }
}

//Deleting function
void delfn(int n)
{
    for(int i=0; i<(n-1)/2; i++)
    temp=temp->next;

    nnode=temp->next;
    temp->next=temp->next->next;
    free(nnode);
    nnode=NULL;
}

//main
int main(void)
{
    head=(ll *)malloc(sizeof(ll));
    printf("Enter number of nodes:");
    scanf("%d",&n);

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


    head->next=NULL;

    temp=head;
    creatinglist(n);
    temp=head;
    delfn(n);
    temp=head;
    printlist(n);
    return 0;
}