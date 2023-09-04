#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *head, *newnode, *ptr;

void create(int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("enter element %d: ", i+1);
        scanf("%d", &newnode->data);
        newnode->link = 0;

        if(head==0)
        {
            head = ptr = newnode;
        }
        else
        {
            ptr->link = newnode;
            ptr = newnode;
        }
    }
}


void travarsel()
{
    ptr = head;
    if(ptr==NULL)
    {
        printf("List empty!");
    }
    else
    {
        while(ptr!=0)
        {
            printf("%d ", ptr->data);
            ptr = ptr-> link;
        }
    }
}

int main()
{
    int i, n, ele;

    head = 0;
    printf("Enter the no. of elements: ");
    scanf("%d", &n);

    create(n);
    
    travarsel();

    return 0;
}