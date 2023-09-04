#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

int main()
{
    struct node *head, *ptr;
    head = 0;

    ptr = head;
    
    if(ptr==0)
    {
        printf("Empty list !");
    }
    else
    {
        while(ptr!=0)
        {
            printf("%d", ptr->data);
            ptr = ptr -> link;
        }
    }

    return 0;
}