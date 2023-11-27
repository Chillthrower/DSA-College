#include <stdio.h>
#include <stdlib.h>

#define MAX 5

struct Queue 
{
    int arr[MAX];
    int front, rear;
};

void initializeQueue(struct Queue *queue) 
{
    queue->front = -1;
    queue->rear = -1;
}

void insertQueue(struct Queue *queue, int element) 
{
    if (queue->rear == MAX - 1) 
    {
        printf("Queue Overflow. Cannot insert element.\n");
    } else 
    {
        if (queue->front == -1) 
        {
            queue->front = 0;
        }
        queue->arr[++(queue->rear)] = element;
        printf("Element inserted successfully.\n");
    }
}

int deleteQueue(struct Queue *queue) 
{
    int element;
    if (queue->front == -1) 
    {
        printf("Queue Underflow. Cannot delete element.\n");
        return -1;
    } else 
    {
        element = queue->arr[queue->front];
        if (queue->front == queue->rear) 
        {
            queue->front = -1;
            queue->rear = -1;
        } else 
        {
            (queue->front)++;
        }
        printf("Element deleted successfully.\n");
        return element;
    }
}

void displayQueueStatus(struct Queue *queue) 
{
    if (queue->front == -1) 
    {
        printf("Queue is empty.\n");
    } else if (queue->rear == MAX - 1) 
    {
        printf("Queue is full.\n");
    } else 
    {
        printf("Queue is not empty. Elements present: %d\n", queue->rear - queue->front + 1);
    }
}

void displayQueueElements(struct Queue *queue) 
{
    if (queue->front == -1) 
    {
        printf("Queue is empty.\n");
    } else 
    {
        printf("Queue elements: ");
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
    initializeQueue(&queue);

    int choice, element;

    do 
    {
        printf("\nMenu:\n");
        printf("1. Insert Element into Queue\n");
        printf("2. Delete Element from Queue\n");
        printf("3. Display Queue Status\n");
        printf("4. Display Queue Elements\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                insertQueue(&queue, element);
                break;

            case 2:
                element = deleteQueue(&queue);
                if (element != -1) 
                {
                    printf("Deleted Element: %d\n", element);
                }
                break;

            case 3:
                displayQueueStatus(&queue);
                break;

            case 4:
                displayQueueElements(&queue);
                break;

            case 5:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}
