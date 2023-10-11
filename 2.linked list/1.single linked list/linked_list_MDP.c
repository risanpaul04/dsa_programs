#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *head, *head2, *head3, *ptr, *newnode;

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

int searchnode(int ele)
{
    int pos = 1;
    struct node *temp = head;
    while (temp!=NULL)
    {
        if (temp->data==ele)
        {
            return pos;
        }
        temp=temp->link;
        pos++;
    }
    return -1;
}

void insert_at_begin()
{
    ptr = head;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->link = ptr;
    head = newnode;
}

void insert_at_end()
{
    ptr = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->link = NULL;

    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = newnode;
}

void insert_at_anyPos()
{
    int i = 1, pos;
    ptr = head;
    printf("Enter the position: ");
    scanf("%d", &pos);
    if (pos == 1)
    {
        insert_at_begin();
    }
    else
    {
        while (i < pos - 1)
        {
            ptr = ptr->link;
            i++;
        }
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("enter element: ");
        scanf("%d", &newnode->data);
        newnode->link = ptr->link;
        ptr->link = newnode;
    }
}

void del_from_begin()
{
    ptr = head;
    if (head != NULL)
    {
        head = ptr->link;
        printf("\nDeleted: %d", ptr->data);
        free(ptr);
    }
    else
    {
        printf("Underflow");
    }
}

void del_from_end()
{
    ptr = head;
    struct node *ptr2 = ptr->link;
    while (ptr2->link != NULL)
    {
        ptr = ptr2;
        ptr2 = ptr2->link;
    }
    ptr->link = NULL;
    printf("\nDeleted: %d", ptr2->data);
    free(ptr2);
}

void del_from_anyPos()
{
    int i = 1, pos;
    printf("Enter the position of the node u want to delete: ");
    scanf("%d", &pos);
    ptr = head;
    struct node *ptr2;
    ptr2 = ptr->link;
    while (i < pos - 1)
    {
        ptr = ptr2;
        ptr2 = ptr2->link;
        i++;
    }
    ptr->link = ptr2->link;
    printf("\nDeleted: %d", ptr2->data);
    free(ptr2);
}

void concat(struct node *Head1, struct node *Head2)
{
    ptr = Head1;
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = Head2;
}

struct node *merge(struct node *Head1, struct node *Head2)
{
    struct node *Head3 = NULL;
    struct node *ptr1 = Head1;
    struct node *ptr2 = Head2;
    struct node *ptr3 = NULL;
    struct node *newnode = NULL;

    while (ptr1 != NULL && ptr2 != NULL)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        if (ptr1->data < ptr2->data)
        {
            newnode->data = ptr1->data;
            ptr1 = ptr1->link;
        }
        else
        {
            newnode->data = ptr2->data;
            ptr2 = ptr2->link;
        }
        newnode->link = NULL;
        if (Head3 == NULL)
        {
            Head3 = newnode;
            ptr3 = newnode;
        }
        else
        {
            ptr3->link = newnode;
            ptr3 = newnode;
        }
    }
    while (ptr1 != NULL)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = ptr1->data;
        newnode->link = NULL;
        ptr3->link = newnode;
        ptr3 = newnode;
        ptr1 = ptr1->link;
    }
    while (ptr2 != NULL)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = ptr2->data;
        newnode->link = NULL;
        ptr3->link = newnode;
        ptr3 = newnode;
        ptr2 = ptr2->link;
    }
    return Head3;
}

void reverse()
{
    struct node *q, *r, *s;
    q = head;
    s = NULL;
    r = q;
    while (q != NULL)
    {
        r = q;
        q = q->link;
        r->link = s;
        s = r;
    }
    head = r;
}

int main()
{
    int n, m, ele, pos;
    int flag = 1;
    int choice;
    head = NULL;
    head2 = NULL;
    head3 = NULL;
    printf("\n\n\t\t\tSingle Linked List\n");

    printf("\n\tCreate a list: \n");
    printf("No. of elements on the list: ");
    scanf("%d", &n);
    create(n, &head);

    // Choices
    while (flag)
    {
        printf("\n\t\t\tMenu\n1. List traversal\t\t2. List element search\n3. Insert element at beginning\t4. Insert at end\n5. Insert at any position\t6. Delete from beginning\n7. Delete from end\t\t8. delete from any position\n9. List reversal\t\t10. List marge\n11. List concatination\t\t12. Exit !\n\n");
        printf("Your choice:  ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // list_traversal;
            display(head);
            break;
        case 2:
            printf("\nEnter an element to search: ");
            scanf("%d", &ele);
            pos = searchnode(ele);
            if (pos != -1)
            {
                printf("%d is present at position %d on the list.", ele, pos);
            }
            else
            {
                printf("Element not present on the list.");
            }
            break;
        case 3:
            insert_at_begin();
            break;
        case 4:
            insert_at_end();
            break;
        case 5:
            insert_at_anyPos();
            break;
        case 6:
            del_from_begin();
            break;
        case 7:
            del_from_end();
            break;
        case 8:
            del_from_anyPos();
            break;
        case 9:
            reverse();
            printf("List after reversal: \n");
            display(head);
            break;
        case 10:
            printf("\nNo. of elements in the 2nd list: ");
            scanf("%d", &m);
            create(m, &head2);
            printf("The 2nd list:\n");
            display(head2);

            head3 = merge(head, head2);
            printf("\nMerged list:\n");
            display(head3);
            break;
        case 11:
            printf("\nNo. of elements in the 2nd list: ");
            scanf("%d", &m);
            create(m, &head2);
            printf("The 2nd list:\n");
            display(head2);

            concat(head, head2);
            printf("\nList after concatination: \n");
            display(head);
            break;
        case 12:
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