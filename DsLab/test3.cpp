#include<stdio.h>
#include<stdlib.h>

#define MAX 50

struct Queue
{
    int arr[MAX];
    int front;
    int rear;
};

void IntialIze(struct Queue *queue)
{
    queue->front = queue->rear = -1;
}

void Enqueue(struct Queue *queue, int elem)
{
    if (queue->rear == MAX - 1)
    {
        printf("Queue iw full");
    }
    else
    {
        if (queue->front == -1)
        {
            queue->front = 0;
        }
        queue->arr[++(queue->rear)] = elem;
        printf("eleemnt added successfully\n");
        
    }
}

void Dequeue(struct Queue *queue)
{
    if (queue->front == -1)
    {
        printf("queue is empty");
    }
    else
    {
        if (queue->front == queue->rear)
        {
            queue->front = -1;
            queue->rear = -1;
        }
        else
        {
            printf("ele %d has been deleted successfully\n", queue->arr[queue->front]);
            ++queue->front;
        }
        
    }
    
}

void display(struct Queue *queue)
{
    if (queue->front == -1)
    {
        printf("queue is empty");
    }
    else
    {
        for (int i = queue->front; i <= queue->rear; i++)
        {
            printf("%d ", queue->arr[i]);
        }

        printf("\n");
    }
}


int main()
{
    struct Queue queue;
    IntialIze(&queue);
    Enqueue(&queue, 1);
    Enqueue(&queue, 2);
    Enqueue(&queue, 3);
    Enqueue(&queue, 4);
    Enqueue(&queue, 5);

    display(&queue);
    Dequeue(&queue);
    display(&queue);

    return 0;

}