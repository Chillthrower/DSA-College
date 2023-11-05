
//DoubleHLL
#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;

typedef struct Node *DoubleLL;

DoubleLL insertAtBeginning(int x) 
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

    return head;
}

DoubleLL insertAtEnd(int x) 
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    if (head == NULL) 
    {
        newNode->prev = NULL;
        head = newNode;
        return head;
    }
    struct Node *temp = head;
    while (temp->next != NULL) 
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

DoubleLL insertAfter(int x, int pos) 
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    if (head == NULL || pos == 1) 
    {
        insertAtBeginning(x);
        return head;
    }

    struct Node *temp = head;
    int count = 1;
    while (temp != NULL && count < pos) 
    {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) 
    {
        printf("Invalid position. Inserting at the end.\n");
        insertAtEnd(x);
        return head;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) 
    {
        temp->next->prev = newNode;
    }
    temp->next = newNode;

    return head;
}

DoubleLL deleteFromBeginning() 
{
    if (head == NULL) 
    {
        printf("Doubly linked list is empty. No element to delete.\n");
        return head;
    }
    struct Node *temp = head;
    head = temp->next;
    if (temp->next != NULL) 
    {
        temp->next->prev = NULL;
    }
    free(temp);

    return head;
}

DoubleLL deleteFromEnd() 

{
    if (head == NULL) 
    
    {
        printf("Doubly linked list is empty. No element to delete.\n");
        return head;
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

    return head;
}

DoubleLL deleteAtPosition(int pos) 
{
    if (head == NULL) 
    {
        printf("Doubly linked list is empty. No element to delete.\n");
        return head;
    }
    if (pos == 1) 
    {
        struct Node *temp = head;
        head = temp->next;
        if (temp->next != NULL) 
        {
            temp->next->prev = NULL;
        }
        free(temp);
        return head;
    }
    struct Node *temp = head;
    int count = 1;
    while (temp != NULL && count < pos) 
    {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) 
    {
        printf("Invalid position. No element found at position %d.\n", pos);
        return head;
    }
    if (temp->prev != NULL) 
    {
        temp->prev->next = temp->next;
    } 
    
    if (temp->next != NULL) 
    {
        temp->next->prev = temp->prev;
    }
    free(temp);

    return head;
}

void search(int key) 
{
    struct Node *temp = head;
    int position = 1;
    int found = 0;
    while (temp != NULL) 
    {
        if (temp->data == key) 
        {
            printf("Element %d found at position %d\n", key, position);
            found = 1;
            break;
        }
        temp = temp->next;
        position++;
    }
    if (!found) 
    {
        printf("Element %d not found in the doubly linked list\n", key);
    }
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
        printf("\n\n*********Main Menu*********\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("\n1.Insert in beginning\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n5.Delete from last\n6.Delete node after specified location\n7.Search for an element\n8.Show\n9.Exit\n");
        printf("\nEnter your choice?\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            printf("Enter element to be inserted: ");
            scanf("%d", &x);
            head = insertAtBeginning(x);
            break;
            case 2:
            printf("Enter element to be inserted at the end: ");
            scanf("%d", &x);
            head = insertAtEnd(x);
            break;
            case 3:
            printf("Enter the element to be inserted: ");
            scanf("%d", &x);
            printf("Enter the position: ");
            scanf("%d", &n);
            head = insertAfter(x, n);
            break;
            case 4:
            head = deleteFromBeginning();
            break;
            case 5:
            head = deleteFromEnd();
            break;
            case 6:
            printf("Enter the position: ");
            scanf("%d", &n);
            head = deleteAtPosition(n);
            break;
            case 7:
            printf("Enter the element to be searched: ");
            scanf("%d", &n);
            search(n);
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
