#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head, *ptr, *newnode;

void createCLL()
{
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    if(head==NULL)
    {
        head = newnode;
        ptr = newnode;
    }
    else
    {
        ptr->next = newnode;
        ptr = newnode;
    }
    newnode->next = head;
}

void display()
{
    if(head==NULL)
    {
        printf("List empty");
    }
    else
    {
        ptr = head;
        while(ptr->next != head)
        {
            printf("[%d] ->", ptr->data);
            ptr = ptr->next;
        }
        printf("[%d]", ptr->data);
    }
}


int main()
{
    head = NULL;

    int flag=1, choice;
    
    while(flag)
    {   
        printf("Enter 1 continue\nEnter 0 to exit!\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        
        if(choice==1)
        {
            createCLL();
        }
        else
        {
            flag = 0;
        }
    }
    display();

    return 0;
}