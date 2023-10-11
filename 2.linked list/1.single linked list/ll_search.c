#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
} *head, *temp, *newnode;

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
            head = temp = newnode;
        }
        else
        {
            temp->link = newnode;
            temp = newnode;
        }
    }
}


void travarsel()
{
    temp = head;
    if(temp==NULL)
    {
        printf("List empty!");
    }
    else
    {
        while(temp!=0)
        {
            printf("%d ", temp->data);
            temp = temp-> link;
        }
    }
}

int searchnode(int ele)
{
    int pos = 1;
    struct node *temp = head;
    while (temp!=NULL)
    {
        if (temp->data==ele)
        {
            return pos;
        }
        temp=temp->link;
        pos++;
    }
    return -1;
}

int main()
{
    int i, n, ele;

    head = 0;
    printf("Enter the no. of elements: ");
    scanf("%d", &n);

    create(n);
    printf("Given list:\n");
    travarsel();
    printf("\nEnter an element to search: ");
    scanf("%d", &ele);
    int pos = searchnode(ele);
    if(pos!=-1)
    {
        printf("%d is present at position %d on the list.", ele, pos);
    }
    else
    {
        printf("Element not present on the list.");
    }

    return 0;
}