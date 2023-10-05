#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *head1, *head2, *head3, *ptr, *ptr1, *ptr2, *ptr3, *newnode;

void create(int n, struct node **header)
{
    int i;
    *header = NULL;
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

struct node* merge(struct node* head1, struct node* head2) {
    struct node* head3 = NULL;
    struct node* ptr1 = head1;
    struct node* ptr2 = head2;
    struct node* ptr3 = NULL;
    struct node* newnode = NULL;

    while (ptr1 != NULL && ptr2 != NULL) {
        newnode = (struct node*)malloc(sizeof(struct node));
        if (ptr1->data < ptr2->data) {
            newnode->data = ptr1->data;
            ptr1 = ptr1->link;
        } else {
            newnode->data = ptr2->data;
            ptr2 = ptr2->link;
        }
        newnode->link = NULL;
        if (head3 == NULL) {
            head3 = newnode;
            ptr3 = newnode;
        } else {
            ptr3->link = newnode;
            ptr3 = newnode;
        }
    }

    while (ptr1 != NULL) {
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = ptr1->data;
        newnode->link = NULL;
        ptr3->link = newnode;
        ptr3 = newnode;
        ptr1 = ptr1->link;
    }

    while (ptr2 != NULL) {
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = ptr2->data;
        newnode->link = NULL;
        ptr3->link = newnode;
        ptr3 = newnode;
        ptr2 = ptr2->link;
    }

    return head3;
}

int main()
{
    int n, m;
    head1 = head2 = head3 = NULL;
    printf("No. of elements in the 1st list: ");
    scanf("%d", &n);
    create(n, &head1);

    printf("\nNo. of elements in the 2nd list: ");
    scanf("%d", &m);
    create(m, &head2);

    display(head1);
    display(head2);

    head3 = merge(head1, head2);

    printf("List after merge:\n");
    display(head3);

    return 0;
}