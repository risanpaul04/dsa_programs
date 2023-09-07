#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i, n, ele, pos;
    struct node
    {
        int data;
        struct node *link;
    };
    struct node *head, *newnode, *ptr;

    head = 0;
    printf("Enter the no. of elements: ");
    scanf("%d", &n);

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

    ptr = head;
    printf("Enter the position: ");
    scanf("%d", &pos);
    if(pos==1)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("enter element: ");
        scanf("%d", &newnode->data);
        newnode->link = head;
        head = newnode;
    }
    else
    {
        for(i=1; i<pos-1; i++)
        {
            ptr = ptr->link;
        }
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("enter element: ");
        scanf("%d", &newnode->data);
        newnode->link = ptr->link;
        ptr->link = newnode;
    }

    ptr = head;
    while(ptr!=0)
    {
        printf("%d ", ptr->data);
        ptr = ptr-> link;
    }
}