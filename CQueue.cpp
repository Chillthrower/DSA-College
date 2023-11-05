#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct CircularQueue 
{
    int items[MAX_SIZE];
    int front, rear;
    int count;
};

void initialize(struct CircularQueue *queue) 
{
    queue->front = -1;
    queue->rear = -1;
    queue->count = 0;
}

void enqueue(struct CircularQueue *queue, int item) 
{
    if (queue->count == MAX_SIZE) 
    {
        printf("Queue is full. Cannot enqueue.\n");
    } 
    else 
    {
        if (queue->front == -1) 
        {
            queue->front = queue->rear = 0;
        } 
        else if (queue->rear == MAX_SIZE - 1) 
        {
            queue->rear = 0;
        } 
        else 
        {
            queue->rear++;
        }
        queue->items[queue->rear] = item;
        queue->count++;
        printf("Enqueued: %d\n", item);
    }
}

int dequeue(struct CircularQueue *queue) 
{
    if (queue->count == 0) 
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    } 
    else 
    {
        int item = queue->items[queue->front];
        if (queue->front == queue->rear) 
        {
            queue->front = queue->rear = -1;
        } 
        else if (queue->front == MAX_SIZE - 1) 
        {
            queue->front = 0;
        } 
        else 
        {
            queue->front++;
        }
        queue->count--;
        printf("Dequeued: %d\n", item);
        return item;
    }
}

void display(struct CircularQueue *queue) 
{
    if (queue->count == 0) 
    {
        printf("Queue is empty.\n");
    } 
    else 
    {
        printf("Queue elements: ");
        int i = queue->front;
        int remaining = queue->count;
        while (remaining > 0) 
        {
            printf("%d ", queue->items[i]);
            remaining--;
            if (i == MAX_SIZE - 1) 
            {
                i = 0;
            } 
            else 
            {
                i++;
            }
        }
        printf("\n");
    }
}

int main() 
{
    struct CircularQueue cq;
    initialize(&cq);
    
    enqueue(&cq, 1);
    enqueue(&cq, 2);
    enqueue(&cq, 3);
    enqueue(&cq, 4);
    enqueue(&cq, 5);
    display(&cq);
    
    dequeue(&cq);
    dequeue(&cq);
    display(&cq);
    
    enqueue(&cq, 6);
    enqueue(&cq, 7);
    display(&cq);
    
    return 0;
}
