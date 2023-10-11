#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
} *tail;

void createCLL(int n)
{
    tail = 0;
    struct node *newnode;

    for(int i=0; i<n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data %d: ", i+1);
        scanf("%d", &newnode->data);

        if(tail==NULL)
        {
            tail = newnode;
            tail->link = newnode;
        }
        else
        {
            newnode->link = tail->link;
            tail->link = newnode;
            tail = newnode;
        }
    }
}

void display()
{
    struct node *temp;
    temp = tail->link;
    if(tail==NULL)
    {
        printf("List empty !");
    }
    else
    {
        while(temp->link!=tail->link)
        {
            printf("[%d] -> ", temp->data);
            temp = temp->link;
        }
        printf("[%d] -> 1st node\n", temp->data);
    }
}

void insert_at_end()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter data: ");
    scanf("%d", &newnode->data);
    if(tail==NULL)
    {
        tail = newnode;
        newnode->link = tail;
    }
    else
    {
       newnode->link = tail->link;
       tail->link = newnode;
       tail = newnode;
    }
}

int main()
{   
    int n;
    printf("\n\t\tinsertion at the end of a Circular linked list\n");
    printf("\nNo. of nodes on the list: ");
    scanf("%d", &n);

    createCLL(n);

    printf("\nThe given list: \n");
    display();

    insert_at_end();

    printf("\nList after insertion:\n");
    display();

    return 0;
}