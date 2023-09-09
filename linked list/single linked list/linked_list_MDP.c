#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *head, *head1, *head2, *ptr, *newnode;

void create(int, struct node **);
void display(struct node*);
int count();

void concat(struct node *, struct node *);

void reverse();

int main()
{
    int i, n, m, choice = 1, flag = 0;

    return 0;
}

void create(int n, struct node **header)
{
    int i;
    for (i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data %d: ", i + 1);
        scanf("%d", &newnode->data);
        newnode->link = NULL;
        if (*header == NULL)
        {
            *header = newnode;
            ptr = newnode;
        }
        else
        {
            ptr->link = newnode;
            ptr = newnode;
        }
    }
}

void display(struct node *header)
{
    ptr = header;
    if (header == NULL)
    {
        printf("List empty !");
    }
    else
    {
        while (ptr != NULL)
        {
            printf("[%d] -> ", ptr->data);
            ptr = ptr->link;
        }
        printf("END\n");
    }
}

int count(struct node *header)
{
    int count = 0;
    ptr = header;
    while(ptr!=NULL)
    {
        count++;
        ptr = ptr -> link;
    }
    return count;
}

void concat(struct node *Head1, struct node *Head2)
{
    ptr = Head1;
    while(ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr ->link = Head2;
}

void reverse(struct node **header)
{
    struct node *q, *r, *s;
    q = *header;
    s = NULL;
    r = q;
    while(q!=NULL)
    {
        r = q;
        q = q->link;
        r -> link = s;
        s = r;
    }
    *header = r;
}