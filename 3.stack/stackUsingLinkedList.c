//             ----- Create stack using linked list  ------

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int top = -1;

struct node *head, *temp, *newnode;

void push()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = NULL;
    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if(head==NULL)
    {
        head = newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
    top++;
}

void pop()
{
    printf("Popped from top: %d\n", head->data);
    if(top<0)
    {
        printf("Underflow !");
    }
    else if(top==0)
    {
        temp = head;
        head = NULL;
        free(temp);
        top--;
    }
    else
    {
        temp = head->next;
        free(head);
        head = temp;
        top--;
    }
}

void peek()
{
    if(top<0)
    {
        printf("Empty stack !");
    }
    else
    {
        printf("Top: %d", head->data);
    }
}

void display()
{
    temp = head;
    printf("Given stack:\n");
    if(top<0)
    {
        printf("list empty !");
    }
    else
    {
        printf("----\n");
        while(temp!=NULL)
        {
            printf("| %d |\n  -- \n", temp->data);
            temp = temp -> next;
        }
    }
}

int main()
{
    int choice, flag=1;
    printf("\n\n\t\tStack");
    while(flag)
    {
        printf("\n\nMenu:\n1.push\n2.pop\n3.peek\n4.display\n5.Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            flag = 0;
            printf("exiting program !");
            break;
        default:
            printf("\nIndalid input.\nchoose a valid option");
            break;
        }
    }

    return 0;
}