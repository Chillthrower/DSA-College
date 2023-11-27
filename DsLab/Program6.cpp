#include <stdio.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int item) 
{
    if ((rear + 1) % MAX_SIZE == front) 
    {
        printf("Queue Overflow: Cannot enqueue %d\n", item);
    } 
    else 
    {
        if (front == -1) 
        {
            front = 0;
        }
        rear = (rear + 1) % MAX_SIZE;
        queue[rear] = item;
        printf("Enqueued: %d\n", item);
    }
}

void dequeue() 
{
    if (front == -1) 
    {
        printf("Queue Underflow: Queue is empty\n");
    } 
    else 
    {
        int deletedItem = queue[front];
        if (front == rear) 
        {
            front = rear = -1;
        } 
        else 
        {
            front = (front + 1) % MAX_SIZE;
        }
        printf("Dequeued: %d\n", deletedItem);
    }
}

void display() 
{
    if (front == -1) 
    {
        printf("Queue is empty\n");
    } 
    else 
    {
        int i = front;
        printf("Queue elements: ");
        do 
        {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX_SIZE;
        } while (i != (rear + 1) % MAX_SIZE);
        printf("\n");
    }
}

int main() 
{
    int choice, item;

    do 
    {
        printf("\n****** Queue Menu ******\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &item);
                enqueue(item);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }

    } while (choice != 4);

    return 0;
}
