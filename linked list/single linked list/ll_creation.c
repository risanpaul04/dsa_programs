#include<STDIO.H>
#include<STDLIB.H>

struct node
{
    int data;
    struct node * link;
};

void main()
{   
    int i, n, el, choice=1;
    struct node *head, *newnode, *temp;
    head = 0;

    while(choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->link = 0;
        if(head==0){
            head=temp=newnode;
        }
        else
        {
            temp->link = newnode;
            temp = newnode;
        }
        printf("enter 1 to continue\nenter 0 to exit\n");
        scanf("%d", &choice);
    }

    temp = head;
    while(temp!=0)
    {
        printf("%d -> ", temp->data);
        temp=temp->link;
    }
}

