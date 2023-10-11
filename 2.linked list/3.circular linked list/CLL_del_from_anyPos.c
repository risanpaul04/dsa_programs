#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
} *head, *temp;

void createCLL(int n){
    head = 0;
    struct node *newnode;

    for(int i=0; i<n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data %d: ", i+1);
        scanf("%d", &newnode->data);

        if(head==NULL)
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
    if(head!=NULL)
    {
        temp = head;
        do
        {
            printf("[%d] -> ", temp->data);
            temp = temp->link;
        }while(temp!=head);
        printf("head\n");
    }
    else
    {
        printf("List empty !\n");
    }
}

int countnodes()
{
    temp = head;
    int count = 0;
    while(temp->link != head)
    {
        count++;
        temp = temp->link;
    }
    count++;
    return count;
}

void del_from_anyPos(int pos)
{
    int i = 1;
    int len = countnodes();
    struct node *curr, *prev;
    prev = head;
    curr = prev->link;
    
    if(pos==1)
    {   
        if(len!=1)
        {
            head = prev->link;
            while(curr->link!=prev)
            {
             curr = curr->link;
            }
            curr->link = head;
            free(prev);
        }
        else
        {
            free(head);
        }
    }
    else
    {
        
        while(i<pos-1)
        {
            curr = curr->link;
            prev = prev->link;
            i++;
        }
        prev->link = curr->link;
        free(curr);
    } 
}

int main()
{   
    int n, pos, len = countnodes();
    printf("\n\t\tDeletion from any position of the Circular linked list\n");
    printf("\nNo. of nodes on the list: ");
    scanf("%d", &n);

    createCLL(n);

    printf("\nThe given list: \n");
    display();
    printf("No. of nodes: %d", len);

    printf("\nPosition of the node you want to delete: ");
    scanf("%d", &pos);

    if(pos<1 || pos>len)
    {
        printf("\nInvalid position !");
    }
    else
    {
        printf("No. of nodes: %d", len);
        del_from_anyPos(pos);
        printf("\nList after deletion of %d no. node: \n", pos);
        display();
    }
   return 0;
}