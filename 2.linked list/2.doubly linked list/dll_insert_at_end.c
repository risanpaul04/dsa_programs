#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head, *tail, *ptr, *newnode;

void createDLL(int n)
{
    int i;
    head = 0;
    for(i= 0; i<n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->next = NULL;
        newnode -> prev = NULL;
        printf("Enter data %d: ", i+1);
        scanf("%d", &newnode->data);
        if(head==0)
        {
            head = tail = newnode;
        }
        else{
            tail -> next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }
}

void display(struct node *header)
{
    ptr = header;
    if (header == NULL)
    {
        printf("List empty !");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("[%d] -> ", ptr->data);
            ptr = ptr->next;
        }
        printf("END\n");
    }
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

int main()
{   int n;
    printf("No. of elements: ");
    scanf("%d", &n);

    createDLL(n);
    display(head);

    insert_at_end();
    display(head);

    return 0;
}