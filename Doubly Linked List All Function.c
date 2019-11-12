#include<stdio.h>
#include<stdlib.h>

typedef struct mylist
{
    int data;
    struct mylist *next;
    struct mylist *prev;
}node;

node *GetNewNode(int data)
{
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

node *InsertAtHead(node *head, int data)
{
    node *newNode = GetNewNode(data);
    node *temp = head->next;
    head->next = newNode;
    newNode->next = temp;
    temp->prev = newNode;
    newNode->prev = head;
    head = newNode;
}

node *insertAtTail(node *head, int data)
{
    node* newNode = GetNewNode(data);
    if(head == NULL)
    {
        head = newNode;
        return;
    }
    while(head->next != NULL)
    {
        head = head->next;
    }
    head->next = newNode;
    newNode->prev = head;
    newNode->next = NULL;
}

node *insertPre(node *head, int search, int data)
{
    node *newNode = GetNewNode(data);
    while (head->next != NULL)
    {
        if(head->next->data == search)
        {
            node *store = head->next;
            head->next = newNode;
            newNode->next = store;
            store->prev = newNode;
            return 0;
        }
        head = head->next;
    }
}

node *insertPos(node *head, int search, int data)
{
    node *newNode = GetNewNode(data);
    while (head->next != NULL)
    {
        if(head->next->data == search)
        {
            node *store = head->next->next;
            head->next->next = newNode;
            newNode->next = store;
            store->prev = newNode;
            newNode->prev = head->next;
            return 0;
        }
        head = head->next;
    }
}

node *replaceData (node *head, int search ,int data)
{
    while (head->next != NULL)
    {
        if (head->next->data == search)
        {
            head->next->data = data;
        }
        head = head->next;
    }
}

node *deletefast(node *head)
{
    node *temp = head->next;
    head->next = head->next->next;
    temp->prev = NULL;
    free(temp);
}

node *deletelast(node *head)
{
    while(head->next != NULL)
    {
        if (head->next->next == NULL)
        {
            node *temp = head->next;
            head->next = NULL;
            free(temp);
            return 0;
        }
        head = head->next;
    }
}

node *deleteData (node *head, int data)
{
    while(head->next != NULL)
    {
        if(head->next->data == data)
        {
            node *store = head->next;
            head->next = store->next;
            store->next->prev = head;
            free(store);
        }
        head = head->next;
    }
}

node *print(node *head)
{
    while(head->next != NULL)
    {
        printf("%d ",head->next->data);
        head = head->next;
    }
}

node *printRev(node *currNode)
{
    while(currNode->next != NULL)
    {
        currNode = currNode->next;
    }
    while(currNode->prev != NULL)
    {
        printf("%d ",currNode->data);
        currNode = currNode->prev;
    }
}

void main()
{
    node *one = (node*)malloc(sizeof(node));
    one->next = NULL;
    one->prev = NULL;
    insertAtTail(one,6);
    insertAtTail(one,7);
    insertAtTail(one,10);
    InsertAtHead(one,2);
    deleteData(one,7);
    //replaceData(one,10,8);
    //insertPos(one,7,9);
    print(one);
    //printRev(one);
}
