#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<ctype.h>
#define MAX 50


int queue[MAX];
int front = -1, rear = -1;

void Enqueue(int ele)
{
    if ((rear + 1) % MAX == front)
    {
        printf("Overflow");
    }
    else 
    {
        if (front == -1) 
        {
            front = 0;
        }
        rear = (rear + 1) % MAX;
        queue[rear] = ele;
        printf("Enqueued: %d\n", ele); //got error here
    }
    
}

void Dequeue()
{
    if(front == -1)
    {
        printf("Underflow");
    }
    else
    {
        int deletedItem = queue[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
        printf("Dequeued: %d\n", deletedItem);
        
    }
}

void display()
{
    if(front == -1)
    {
        printf("Underflow");
    }
    else
    {
        for (int i = front; i < rear + 1; i++)
        {
            printf("%d", queue[i]);
        }

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
                Enqueue(item);
                break;

            case 2:
                Dequeue();
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
