//  C Program to create a Circular linked list using only tail pointer

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *tail;

void createCLL_w_tail(int n){
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

int main()
{
    int n;
    printf("No. of nodes on the list: ");
    scanf("%d", &n);

    createCLL_w_tail(n);
    printf("\nThe given list: \n");
    display();

    return 0;
}