#include <stdio.h>
#include <stdlib.h>

// Node structure for singly linked list
struct Node 
{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Function to insert data at the front of the SLL
void insertFront(int x) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = head;
    head = newNode;
    printf("Inserted %d at the front of the list.\n", x);
}

// Function to display the status of the SLL and count the number of nodes
void displayAndCount() 
{
    struct Node* temp = head;
    int count = 0;

    printf("Singly Linked List Status:\n");
    while (temp != NULL) 
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
        count++;
    }

    printf("NULL\n");
    printf("Number of nodes: %d\n", count);
}

// Function to demonstrate a stack using SLL
void push(int element) 
{
    insertFront(element);
}

void pop() 
{
    if (head == NULL) 
    {
        printf("Stack Underflow: Stack is empty\n");
    } 
    else 
    {
        struct Node* temp = head;
        head = head->next;
        printf("Popped: %d\n", temp->data);
        free(temp);
    }
}

// Peek function for the stack
void peekStack() 
{
    if (head == NULL) 
    {
        printf("Stack is empty\n");
    } 
    else 
    {
        printf("Top element of the stack: %d\n", head->data);
    }
}

int main() 
{
    int choice, data;

    do 
    {
        printf("\n****** Main Menu ******\n");
        printf("1. Create a SLL using front insertion\n");
        printf("2. Display SLL and count nodes\n");
        printf("3. Demonstrate Stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter data to insert at the front: ");
                scanf("%d", &data);
                insertFront(data);
                break;

            case 2:
                displayAndCount();
                break;

            case 3:
                printf("\nStack Operations:\n");
                printf("1. Push\n");
                printf("2. Pop\n");
                printf("3. Peek\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice) 
                {
                    case 1:
                        printf("Enter element to push: ");
                        scanf("%d", &data);
                        push(data);
                        break;

                    case 2:
                        pop();
                        break;

                    case 3:
                        peekStack();
                        break;

                    default:
                        printf("Invalid choice for stack operations.\n");
                }
                break;

            case 4:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    return 0;
}
