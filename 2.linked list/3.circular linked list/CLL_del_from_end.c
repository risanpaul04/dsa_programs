#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
} *head, *temp;

void createCLL(int n)
{
    head = 0;
    struct node *newnode;

    for (int i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data %d: ", i + 1);
        scanf("%d", &newnode->data);

        if (head == NULL)
        {
            head = temp = newnode;
            newnode->link = head;
        }
        else
        {
            temp->link = newnode;
            newnode->link = head;
            temp = newnode;
        }
    }
}

void display()
{
    if (head != NULL)
    {
        temp = head;
        do
        {
            printf("[%d] -> ", temp->data);
            temp = temp->link;
        } while (temp != head);
        printf("head\n");
    }
    else
    {
        printf("List empty !\n");
    }
}

void del_from_end()
{
    
}

int main()
{
    int n;
    printf("\n\t\tDeletion from beginning of the Circular linked list\n");
    printf("\nNo. of nodes on the list: ");
    scanf("%d", &n);

    createCLL(n);

    printf("\nThe given list: \n");
    display();

    del_from_end();

    printf("\nList after deletion from end: \n");
    display();

    return 0;
}