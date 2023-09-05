#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;;
};
struct node *head, *newnode, *temp;

void display()
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
    temp = head;
}


int main()
{
    struct node *one;
    struct node *two;
    struct node *three;

    one = (struct node*)malloc(sizeof(struct node));
    two = (struct node*)malloc(sizeof(struct node));
    three = (struct node*)malloc(sizeof(struct node));

    one->data = 1;
    two ->data = 2;
    three -> data =3;
    
    one ->link = two;
    two -> link = three;
    three -> link = NULL;

    head = one;
    temp = head;

   display();


    newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter data you want to insert: ");
    scanf("%d", &newnode->data);
    newnode -> link = 0;

    while(temp->link != 0)
    {
        temp = temp->link;
    }
    temp -> link = newnode;

    display();
    
    return 0;
}