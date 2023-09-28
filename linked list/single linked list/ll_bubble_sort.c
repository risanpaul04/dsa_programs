#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *head, *ptr, *newnode;

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



void bubble_sort(struct node *header){
    int len = countnode();

    for(int i=0; i<len-1; i++){
        for(int j=0; j<len-i-1; j++){
            if(arr[j]>arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
    }
}

int main()
{
    int n, m;
    printf("No. of elements in the 1st list: ");
    scanf("%d", &n);
    create(n, &head);

    


}