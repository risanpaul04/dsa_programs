//work in progress

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *head, *head1, *head2, *ptr, *newnode;

void create(int n, struct node **header);
void display(struct node*);
int count();

void concat(struct node *, struct node *);

void reverse();

int main()
{
    int n, m;
    int flag = 1;
    int choice;
    printf("\n\n\t\tSingle Linked List\n");

    printf("\n\tCreate a list: \n");
    printf("No. of elements on the list: ");
    scanf("%d", &n);
    create(n, &head);

    //Choices
    while(flag){
        printf("Choose any operation from the list below: \n");
        printf("\n1. List traversal");
        printf("\n2. List element search");
        printf("\n3. List element insertion");
        printf("\n4. List element deletion");
        printf("\n5. List reversal");
        printf("\n6. List marge");
        printf("\n7. List concatination");
        printf("\n8. Exit !\n\n");
        printf("Your choice:  ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                // list_traversal;
                display(head);
                break;
            case 2:
                // list_element_search;
                break;
            case 3:
                // list_insertion();
                break;
            case 4:
                // list_deletion();
                break;
            case 5:
                // list_reversal
                reverse(&head);
                printf("List after reversal: \n");
                display(head);
                break;
            case 6:
                // list marge
                break;
            case 7:
                //list concatination
                printf("\nNo. of elements in the 2nd list: ");
                scanf("%d", m);
                create(m, &head2);

                concat(head, head2);
                printf("\nList after concatination: \n");
                display(head);
                break;
            case 8:
                printf("Exiting Program.\nHappy Coding !");
                flag = 0;
                break;
            default:
                printf("> Invalid input. Choose any number from the Menu...");
                break;
        }
        printf("\n");
    }
    

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

int countnode(struct node *header)
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