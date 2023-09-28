//Program for writing, testing & fixing new algos

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
} *head, *tail;

struct node *ptr, *newnode;

void create(int n, struct node **header)
{
    int i;
    for(i=0; i<n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data %d: ", i+1);
        scanf("%d", &newnode->data);
        newnode ->next = NULL;
        newnode -> prev = NULL;

        if (*header==NULL)
        {
            *header = newnode;
            tail = newnode;
        }
        else
        {
            tail -> next = newnode;
            newnode -> prev = tail;
            tail = newnode;
        }
        
    }
}

void display(struct node *header)
{
    ptr = header;
    if(ptr == NULL)
    {
        printf("List empty !");
    }
    else
    {
        while(ptr != NULL)
        {
            printf("[%d] -> ", ptr->data);
            ptr = ptr -> next;
        }
        printf("END!\n");
    }
}

int countNode()
{
    int count = 0;
    ptr = head;

    while(ptr != NULL)
    {
        count++;
        ptr = ptr -> next;
    }
    return count;
}

void insert_at_begin()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode -> prev = NULL;
    newnode -> next = head;
    head = newnode;
}

void insert_at_end()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    tail -> next = newnode;
    newnode -> prev = tail;
    tail = newnode;
}

void reverseDLL()
{
    struct node *current = head;
    struct node *nextnode;
    
    while(current!=NULL)
    {   
        nextnode = current->next;
        current->next = current->prev;
        current->prev = nextnode;
        current = nextnode;
    }

    current = head;
    head = tail;
    tail = current;
}

int main()
{
    int n;
    printf("No. of nodes: ");
    scanf("%d", &n);

    create(n, &head);
    printf("The given list:\n");
    display(head);

    return 0;
}