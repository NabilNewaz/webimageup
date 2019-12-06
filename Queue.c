#include<stdio.h>

typedef struct mylist
{
    int data;
    struct mylist *next;
}node;

node *insert (node *head,int data)
{
    while (head->next != NULL)
    {
        head = head->next;
    }
    head->next = (node*)malloc(sizeof(node));
    if(head->next == NULL)
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
        head->next->data = data;
        head->next->next = NULL;
    }
    printf("\nInsertion is Success!!!\n");
}

node *delete(node *head)
{
    if(head->next == NULL)
    {
        printf("\nQueue is Empty!!!\n");
    }
    else
    {
        node *temp = head->next;
        head->next = head->next->next;
        printf("\nDeleted element: %d\n", temp->data);
        free(temp);
    }
}

node *display (node *head)
{
    if(head->next == NULL)
    {
        printf("\nQueue is Empty!!!\n");
    }
    else
    {
        printf("\nDisplay Queue List : ");
        while (head->next != NULL)
        {
            printf("%d ",head->next->data);
            head = head->next;
        }
        printf("\n");
    }
}

void main()
{
    node *queue = (node*)malloc(sizeof(node));
    queue->next = NULL;
    int choice, value;
    printf("\n:: Queue Implementation using Linked List ::\n");
    while(1){
        printf("\n****** MENU ******\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
        case 1: printf("Enter the value to be insert: ");
            scanf("%d", &value);
            insert(queue,value);
            break;
        case 2: delete(queue); break;
        case 3: display(queue); break;
        case 4: exit(0);
        default: printf("\nWrong selection!!! Please try again!!!\n");
        }
    }
}
