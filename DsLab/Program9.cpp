
//DoubleLL
#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;

void insertAtBeginning(int x) 
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL) 
    {
        head->prev = newNode;
    }
    head = newNode;
}

void insertAtEnd(int x) 
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    if (head == NULL) 
    {
        newNode->prev = NULL;
        head = newNode;
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL) 
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteFromBeginning() 
{
    if (head == NULL) 
    {
        printf("Doubly linked list is empty. No element to delete.\n");
        return;
    }
    struct Node *temp = head;
    head = temp->next;
    if (temp->next != NULL) 
    {
        temp->next->prev = NULL;
    }
    free(temp);
}

void deleteFromEnd() 
{
    if (head == NULL) 
    {
        printf("Doubly linked list is empty. No element to delete.\n");
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL) 
    {
        temp = temp->next;
    }
    if (temp->prev != NULL) 
    {
        temp->prev->next = NULL;
    } 
    else 
    {
        head = NULL;
    }
    free(temp);
}

void display() 
{
    struct Node *temp = head;
    while (temp != NULL) 
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() 
{
    int choice = 0, x, n;
    while (choice != 9) 
    {
        printf("\n*********Main Menu*********\n");
        printf("Choose one option from the following list ...\n");
        printf("===============================================\n");
        printf("1. Insert at the beginning\n2. Insert at the end\n3. Insert at any random location\n4. Delete from the beginning\n5. Delete from the end\n6. Delete node after specified location\n7. Search for an element\n8. Show\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &x);
                insertAtBeginning(x);
                break;
            case 2:
                printf("Enter the element to be inserted at the end: ");
                scanf("%d", &x);
                insertAtEnd(x);
                break;
            case 4:
                deleteFromBeginning();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 8:
                display();
                break;
            case 9:
                exit(0);
                break;
            default:
                printf("Please enter a valid choice.\n");
        }
    }
    return 0;
}