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
    for(i=0; i<n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter element %d: ", i+1);
        scanf("%d", &newnode->data);
        newnode->link = 0;
        if(head==NULL)
        {
            head = newnode;
            ptr = newnode;
        }
        else
        {
            ptr->link = newnode;
            ptr = newnode;
        }
    }
}

void display(struct node *header)
{
    ptr = header;
    while(ptr!=NULL)
    {
        printf("[%d] -> ", ptr->data);
        ptr = ptr->link;
    }
    printf("END");
}

void reverse()
{
    struct node *q, *r, *s;
    q = head;
    r = q;
    s = NULL;
    while(q!=NULL)
    {
        r = q;
        q = q -> link;
        r -> link = s;
        s = r;
    }
    head = r;
}

int main()
{
    int i, n;
    printf("Enter the no. of elements in the linked list: ");
    scanf("%d", &n);

    create(n);

    display(head);

    reverse();
    printf("\nThe reversed list: \n");
    display(head);
    return 0;
}