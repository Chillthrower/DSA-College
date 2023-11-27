
//CircularLL
#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertAtBeginning(int x) 
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    if (head == NULL) 
    {
        newNode->next = newNode;
        head = newNode;
        return;
    } 
    else 
    {
        struct Node *temp = head;
        while (temp->next != head) 
        {
            temp = temp->next;
        }
        newNode->next = head;
        head = newNode;
        temp->next = newNode;
    }
}

void insertAtEnd(int x) 
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    if (head == NULL) 
    {
        newNode->next = newNode;
        head = newNode;
    } 
    else 
    {
        struct Node *temp = head;
        while (temp->next != head) 
        {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
    }
}

void deleteFromBeginning() 
{
    if (head == NULL) 
    {
        printf("Circular linked list is empty. No element to delete.\n");
        return;
    }
    if (head->next == head) 
    {
        free(head);
        head = NULL;
    } else 
    {
        struct Node *temp = head;
        while (temp->next != head) 
        {
            temp = temp->next;
        }
        struct Node *temp2 = head;
        head = head->next;
        temp->next = head;
        free(temp2);
    }
}

void deleteFromEnd() 
{
    if (head == NULL) 
    {
        printf("Circular linked list is empty. No element to delete.\n");
        return;
    }
    if (head->next == head) 
    {
        free(head);
        head = NULL;
    } else 
    {
        struct Node *temp = head;
        struct Node *prev = NULL;
        while (temp->next != head) 
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        free(temp);
    }
}

void display() 
{
    if (head == NULL) 
    {
        printf("Circular linked list is empty.\n");
        return;
    }
    struct Node *temp = head;
    do 
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf(" (Head)\n");
}

int main() 
{
    int choice = 0, x, n;
    while (choice != 9) 
    {
        printf("\n\n*********Main Menu*********\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("\n1.Insert in beginning\n2.Insert at last\n4.Delete from Beginning\n5.Delete from last\n8.Show\n9.Exit\n");
        printf("\nEnter your choice?\n");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                printf("Enter element to be inserted: ");
                scanf("%d", &x);
                insertAtBeginning(x);
                break;
            case 2:
                printf("Enter element to be inserted at the end: ");
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