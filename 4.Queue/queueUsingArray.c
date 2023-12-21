
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#define MAX_SIZE 10

typedef struct arr_queue
{
    int arr[MAX_SIZE];
    int front;
    int rear;
} Queue;

Queue *createQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int isEmpty(Queue *queue)
{
    return queue->front == -1;
}

int isFull(Queue *queue)
{
    return queue->rear == MAX_SIZE - 1;
}

void enqueue(Queue *queue, int element)
{
    if (isFull(queue))
    {
        printf("Queue is full\n");
        return;
    }
    queue->rear++;
    queue->arr[queue->rear] = element;
    if (isEmpty(queue))
    {
        queue->front++;
    }
}

int dequeue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return -1;
    }
    int element = queue->arr[queue->front];
    queue->front++;
    if (queue->front > queue->rear)
    {
        queue->front = -1;
        queue->rear = -1;
    }
    return element;
}

void printQueue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = queue->front; i <= queue->rear; i++)
    {
        printf("%d ", queue->arr[i]);
    }
    printf("\n");
}

int main()
{
    Queue *queue = createQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    printQueue(queue);
    dequeue(queue);
    printQueue(queue);
    enqueue(queue, 40);
    printQueue(queue);
    return 0;
}
