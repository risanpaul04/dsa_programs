#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct {
    struct Node* front;
    struct Node* rear;
} Queue;

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void initQueue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

int isEmpty(Queue* queue) {
    return queue->front == NULL;
}

void enqueue(Queue* queue, int data) {
    struct Node* node = newNode(data);
    if (isEmpty(queue)) {
        queue->front = node;
        queue->rear = node;
    } else {
        queue->rear->next = node;
        queue->rear = node;
    }
}

// Implement a function to remove the front node from the queue by updating front pointer and freeing the memory of the removed node
void dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
    } else {
        struct Node* temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
    }
}

// Implement a function to display the elements of the queue by traversing the nodes from front to rear
void display(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
    } else {
        struct Node* temp = queue->front;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Test the queue implementation
int main() {
    Queue queue;
    initQueue(&queue);
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    display(&queue);
    dequeue(&queue);
    display(&queue);
    enqueue(&queue, 7);
    display(&queue);
    return 0;
}
