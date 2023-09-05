#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *head, *ptr, *new;

int main(){
     /* Initialize nodes */
struct node *head;
struct node *one = NULL;
struct node *two = NULL;
struct node *three = NULL;
struct node *new = NULL;

/* Allocate memory */
one = malloc(sizeof(struct node));
two = malloc(sizeof(struct node));
three = malloc(sizeof(struct node));
new =(struct node *)malloc(sizeof(struct node));

/* Assign data values */
one->data = 1;
two->data = 2;
three->data=3;

/* Connect nodes */
one->link = two;
two->link = three;
three->link = NULL;

/* Save address of first node in head */
head = ptr = one;

while(ptr!=0){
    printf("%d ", ptr->data);
    ptr = ptr -> link;
}

printf("\nEnter data you want to insert: ");
scanf("%d", &new->data);
new->link = head;
head = new;

// if(new==NULL)
// {
//     printf("Insufficient memory");
//     exit;
// }
// else
// {
//     new->data = 10;
//     new->link = head;
//     head -> link = new;
// }

    ptr = head;
    while(ptr!=0){
    printf("%d ", ptr->data);
    ptr = ptr -> link;
}
    return 0;
}
