#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *head1, *head2, *head3, *ptr, *newnode;

void create(int n, struct node **header)
{   
    int i;
    for(i=0; i<n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data %d: ", i+1);
        scanf("%d", &newnode->data);
        newnode -> link = NULL;
        if(*header==NULL)
        {   
            *header = ptr = newnode;
            
        }
        else
        {
            ptr -> link = newnode;
            ptr = newnode;
        }
    }
}

void display(struct node *Header)
{   
    ptr = Header;
    if(Header==NULL){
        printf("Empty list !");
    }
    else
    {
        while(ptr!=0)
        {
            printf("[%d] -> ", ptr->data);
            ptr = ptr -> link;
        }
    }
    printf("END\n");
}

int main()
{
    int i, n, m;
    head1= NULL;
    head2= 0;

    printf("No. of elements on 1st list: ");
    scanf("%d", &n);
    create(n, &head1);
    printf("\n1st list: \n");
    display(head1);

    printf("\n");
    printf("No. of elements on the 2nd list: ");
    scanf("%d", &m);
    create(m, &head2);
    printf("\n2nd list: \n");
    display(head2);

    //concatination logic

    head3 = ptr = head1;
    while(ptr->link!=NULL)
    {
        ptr = ptr -> link;
    }
    ptr -> link = head2;
    // printf("\n%d\n", p->data);
    printf("\nList after concatination: \n");
    display(head1);

    return 0;
}