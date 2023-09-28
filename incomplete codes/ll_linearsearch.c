#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *head, *ptr, *newnode;

void create(int n)
{
    int i;
    ptr = head;
    for(i=0; i<n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode ->link = NULL;
        printf("Enter data %d: ", i+1);
        scanf("%d", &newnode->data);
        if(ptr==NULL)
        {
            head = newnode;
            ptr = newnode;
        }
        else
        {
            ptr -> link = newnode;
            ptr = newnode;
        }
    }
}

void display()
{
    ptr = head;
    if(ptr==NULL)
    {
        printf("List empty !");
    }
    else
    {
        while(ptr!=NULL)
        {
            printf("[%d] -> ", ptr->data);
            ptr = ptr->link;
        }
        printf("NULL");
    }
}

void llsearch()
{
    
}

int main()
{
    int n, pos, key;
    printf("Enter no. of nodes in the list: ");
    scanf("%d", &n);

    create(n);
    printf("The given list:\n");
    display();

    return 0;
}