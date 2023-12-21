#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *rear = NULL;
struct node *front = NULL; // Add this line to initialize the front pointer

struct node *getnode()
{
	struct node *new;
	new = (struct node *)malloc(sizeof(struct node));
	return new;
}

void enqueue(int x)
{
    struct node *new;
    new = getnode();
    new->data = x;
    new->next = NULL;
       

    if (front->next == NULL && rear->next == NULL)
    {
        front = new;
        rear = new;
    }
    else
    {
        rear->next = new;
        rear = new;
    }
	printf("Enqueue successful");
}
void dequeue()
{
    struct node *temp;
    if (front->next == NULL && rear->next == NULL)
    {
        printf("queue is empty");
    }
    else
    {
        temp = front;
        front = front->next;
        free(temp);
    }
    }

    void display()
    {
        struct node *ptr;
        ptr = front;
        while (ptr != NULL)
        {
            printf(" %d ", ptr->data);
            ptr = ptr->next;
        }
    }


int main()
{
enqueue(1);
enqueue(2);
enqueue(13);
enqueue(15);

 display();
    return 0;
}