#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head, *temp, *newnode;

void create()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    newnode->prev = NULL;
    if(head==NULL)
    {
        head = newnode;
        temp = head;
    }
    else
    {   
        temp -> next = newnode;
        newnode -> prev = temp;
        temp = newnode;
    }
}

void display(struct node *header)
{
    temp = header;
    if (header == NULL)
    {
        printf("List empty !");
    }
    else
    {
        while (temp != NULL)
        {
            printf("[%d] -> ", temp->data);
            temp = temp->next;
        }
        printf("END\n");
    }
}

int main(){
    head = NULL;
    int flag = 1;
    while(flag)
    {   create();
        printf("\npress 1 to continue\npress 0 to exit\n");
        scanf("%d", &flag);
    }
    printf("\nThe given list:\n");
    display(head);
    
    return 0;
}

