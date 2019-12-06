#include<stdio.h>

typedef struct mylist
{
    int data;
    struct mylist *next;
}node;

node *push(node *head, int data)
{
    node *temp = head->next;
    head->next = (node*)malloc(sizeof(node));
    head->next->data = data;
    head->next->next = temp;
    printf("\nInsertion is Success!!!\n");
}

node *pop(node *head)
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
    node *stack = (node*)malloc(sizeof(node));
    stack->next = NULL;
    int choice, value;
    printf("\n:: Stack using Linked List ::\n");
    while(1)
    {
        printf("\n****** MENU ******\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the value to be insert: ");
                scanf("%d", &value);
                push(stack,value);
                break;
            case 2: pop(stack); break;
            case 3: display(stack); break;
            case 4: exit(0);
            default: printf("\nWrong selection!!! Please try again!!!\n");
        }
    }
}
