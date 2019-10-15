#include<stdio.h>
#include<stdlib.h>

typedef struct mylist
{
    int data;
    struct mylist *next;
}node;

node *insert (node *hade, int data)
{
    while (hade->next != NULL)
    {
        hade = hade->next;
    }
    hade->next = (node*)malloc(sizeof(node));
    if(hade->next == NULL)
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
        hade->next->data = data;
        hade->next->next = NULL;
    }
}

node *insertFast(node *hade, int data)
{
    node *temp = hade->next;
    hade->next = (node*)malloc(sizeof(node));
    hade->next->data = data;
    hade->next->next = temp;
}

node *insertBefore(node *hade, int search, int data)
{
    while(hade->next != NULL)
    {
        if(hade->next->data == search)
        {
            node *store = hade->next;
            hade->next = (node*) malloc(sizeof(node));
            hade->next->data = data;
            hade->next->next = store;
            return 0;
        }
        hade = hade->next;
    }
}

node *deletefast(node *hade)
{
    node *temp = hade->next;
    hade->next = hade->next->next;
    free(temp);
}

node *deletelast(node *hade)
{
    while(hade->next != NULL)
    {
        if (hade->next->next == NULL)
        {
            node *temp = hade->next;
            hade->next = NULL;
            free(temp);
            return 0;
        }
        hade = hade->next;
    }
}

node *deleteData (node *hade, int data)
{
    while(hade->next != NULL)
    {
        if(hade->next->data == data)
        {
            node *temp = hade->next;
            hade->next = hade->next->next;
            free(temp);
        }
        hade = hade->next;
    }
}

node *deletePosition(node *hade, int data)
{
    int count = 0;
    while(hade->next != NULL)
    {
        ++count;
        if (count == data )
        {
            node *temp = hade->next;
            hade->next = hade->next->next;
            free(temp);
            return 0;
        }
        hade = hade->next;
    }
        if(data>count || data <= 0)
    {
        printf("Node Not Found");
    }
}

node *countNode(node *hade)
{
    int count = 0;
    while (hade->next != NULL)
    {
        count++;
        hade=hade->next;
    }
    printf("\nTotal Node : %d",count);
}

node *searchNode(node *hade, int data)
{
    int pos = 0;
    int count = 0;
    while(hade->next != NULL)
    {
        ++pos;
        if (hade->next->data == data)
        {
            ++count;
            printf("\nFind Search Data %d time in %d position",count,pos);
        }
        hade=hade->next;
    }
}

node *display (node *hade)
{
    printf("\nDisplay Linked List : ");
    while (hade->next != NULL)
    {
        printf("%d",hade->next->data);
        hade = hade->next;
    }
}

void main()
{
    node *one = (node*)malloc(sizeof(node));
    one->next = NULL;
    insert(one,5);
    insert(one,3);
    insert(one,1);
    insert(one,9);
    insert(one,3);
    deletelast(one);
    deletePosition(one,2);
    display(one);
    countNode(one);
    searchNode(one,3);
}
///Full Code Writen By Nabil Newaz
