#include<stdio.h>
#include<stdlib.h>

#define MAX 10

struct Queue
{   
    int front;
    int rear;
    int data[MAX];
};

void intialize(struct Queue *queue)
{
    queue->front = -1;
    queue->rear = -1;
}

void insert(struct Queue *queue, int value)
{
    if (((queue->rear == MAX - 1) && (queue->front == 0)))
    {
        printf("Overflow \n");
        return;
    }

    if (queue->front == -1)
    {
            queue->front = 0;
            queue->rear = 0;
    }
    else
    {
        queue->rear = queue->rear + 1;
    }

    queue->data[queue->rear] = value;
    printf("ele inserted : %d\n", value);
}

void del(struct Queue *queue)
{
    if (queue->front == -1)
    {
        printf("Underflow");
        return;
    }
    
    int value = queue->data[queue->front];
    if (queue->front == queue->rear)
    {
        queue->front = -1;
        queue->rear = -1;
    }
    else
    {
        queue->front = queue->front + 1;
    }

    printf("ele deleted : %d\n", value);
    
}

void display(struct Queue *queue)
{
    printf("inserted ele : ");
    int temp = queue->front;
    while (temp != queue->rear + 1)
    {
        printf(" %d", queue->data[temp]);
        temp++;
    }
    
}

int main()
{
    struct Queue queue;
    intialize(&queue);

    insert(&queue, 1);
    insert(&queue, 2);
    insert(&queue, 3);
    insert(&queue, 4);
    insert(&queue, 5);
    insert(&queue, 6);

    del(&queue);
    display(&queue);

    return 0;
}
