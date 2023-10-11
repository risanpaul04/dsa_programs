#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *tail;

void createCLL(int n){
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
            tail->next = newnode;
        }
        else
        {
            newnode->next = tail->next;
            tail->next = newnode;
            tail = newnode;
        }
    }
}

void display()
{
    struct node *temp = tail->next;
    while(temp->next != tail->next)
    {
        printf("[%d] -> ", temp->data);
        temp = temp->next;
    }
    printf("[%d]", tail->data);
}


int countnodes()
{
    struct node *temp = tail->next;
    int count = 0;
    while(temp->next != tail->next)
    {
        count++;
        temp = temp->next;
    }
    count++;

    return count;
}

void insert_at_pos()
{
    int pos, i = 1;
    int len = countnodes();

    struct node *newnode, *temp;
    printf("\nEnter position: ");
    scanf("%d", &pos);

    if(pos<0 || pos>len+1)
    {
        printf("Invalid position !");
    }
    else if(pos==1 || pos==len+1)
    {   
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = tail->next;
        tail->next = newnode;
        if(pos==len+1)
        {
            tail = newnode;
        }
    }
    else
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);

        temp = tail->next;

        while(i<pos-1)
        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

int main()
{   
    int n;
    printf("\n\t\tinsertion at any position in Circular linked list\n");
    printf("\nNo. of nodes on the list: ");
    scanf("%d", &n);

    createCLL(n);

    printf("\nThe given list: \n");
    display();
    printf("\nNo. of nodes: %d", countnodes());


    insert_at_pos();

    printf("\nList after insertion:\n");
    display();

    printf("\nNo. of nodes: %d", countnodes());

    return 0;
}