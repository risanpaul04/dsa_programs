#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
} *head, *temp, *newnode;

void dll_create(int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->next = NULL;
        newnode->prev = NULL;
        printf("Enter data %d: ", i+1);
        scanf("%d", &newnode->data);
        if(head!=NULL)
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
        else{
            head = newnode;
            temp = newnode;
        }
    }
}

void display()
{
    temp = head;
    if(temp!=NULL)
    {
        while(temp!=NULL)
        {
            printf("[%d] <=> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
    else
    {
        printf("list empty !");
    }
}

void insert_at_begin()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode -> prev = NULL;
    newnode -> next = head;
    head = newnode;
}

void insert_at_end()
{
    temp= head;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
    newnode->next = NULL;
}

void insert_at_anyPos()
{
    int i = 1, pos;
    printf("Enter the position for insertion: ");
    scanf("%d", &pos);
    temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    while(i<pos-1)
    {
        temp = temp -> next;
        i++;
    }
    newnode -> prev = temp;
    newnode -> next = temp -> next;
    temp -> next = newnode;
}

void del_from_begin()
{
    temp = head;
    head = temp->next;
    temp->next->prev = NULL;
    free(temp);
}

void del_from_end()
{
    temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}

void del_from_anyPos()
{
    int i=1, pos;
    struct node *ptr1, *ptr2, *ptr3;
    printf("Enter the position of the node: ");
    scanf("%d", &pos);
    ptr1 = head;
    ptr2 = ptr1->next;
    while(i<pos-1)
    {
        ptr1 = ptr2;
        ptr2 = ptr2->next;
        i++;
    }
    ptr1->next = ptr2->next;
    ptr3 = ptr2->next;
    ptr3->prev = ptr2->prev;
    free(ptr2);
}

int main()
{
    int n;
    int flag = 1;
    int choice;
    head = NULL;
    printf("\n\n\t\t\tDoubly Linked List\n");

    printf("\n\tCreate a list: \n");
    printf("No. of elements on the list: ");
    scanf("%d", &n);
    dll_create(n);

    // Choices
    while (flag)
    {
        printf("\n\t\t\tMenu\n1. List traversal\t\t2. Insert element at beginning\n3. Insert at end\t\t4. Insert at any position\n5. Delete from beginning\t6. Delete from end\n7. Delete from any position\t8. Exit !\n\n");
        printf("Your choice:  ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("List:\n");
            display();
            break;
        case 2:
            insert_at_begin();
            printf("List after insertion at beginning:\n");
            display();
            break;
        case 3:
            insert_at_end();
            printf("List after insertion at end:\n");
            display();
            break;
        case 4:
            insert_at_anyPos();
            printf("List after insertion at position:\n");
            display();
            break;
        case 5:
            del_from_begin();
            printf("List after deletion from beginning:\n");
            display();
            break;
        case 6:
            del_from_end();
            printf("List after deletion from end:\n");
            display();
            break;
        case 7:
            del_from_anyPos();
            printf("List after deletion from a position:\n");
            display();
            break;
        case 8:
            printf("Exiting Program.\nHappy Coding !");
            flag = 0;
            break;
        default:
            printf(">_ Invalid input. Choose any number from the Menu...");
            break;
        }
        printf("\n");
    }

    return 0;
}