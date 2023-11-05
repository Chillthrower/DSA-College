#include <stdio.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

void insert(int item) 
{
    if (rear == MAX_SIZE - 1) 
    {
        printf("Queue Overflow: Cannot insert %d\n", item);
    } 
    else 
    {
        if (front == -1) 
        {
            front = 0;
        }
        rear++;
        queue[rear] = item;
        printf("Inserted %d into the queue\n", item);
    }
}

void del() 
{
    if (front == -1 || front > rear) 
    {
        printf("Queue Underflow: Queue is empty\n");
    } 
    else 
    {
        int deletedItem = queue[front];
        front++;
        printf("Deleted %d from the queue\n", deletedItem);
    }
}

void display() 
{
    if (front == -1 || front > rear) 
    {
        printf("Queue is empty\n");
    } 
    else 
    {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) 
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() 
{
    insert(1);
    insert(2);
    insert(3);
    display();
    del();
    display();
    insert(4);
    display();
    del();

    return 0;
}
