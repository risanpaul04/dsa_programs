#include<stdio.h>
#include<stdlib.h>

struct node{
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

int main()
{
    int n;
    printf("No. of elements: ");
    scanf("%d", &n);
    create(n);  //calling the create func

    head = 0;


    //Traversal logic
    ptr = head;
    if(ptr==0)
    {
        printf("Empty list !");
    }
    else
    {
        while(ptr!=0)
        {
            printf("%d", ptr->data);
            ptr = ptr -> link;
        }
    }

    return 0;
}