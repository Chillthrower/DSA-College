
//CircularHLL
#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

typedef struct Node *CircularLL;

CircularLL insertAtBeginning(int x) 
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    if (head == NULL) 
    {
        newNode->next = newNode;
        head = newNode;
    } else 
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
    return head;
}

CircularLL insertAtEnd(int x) 
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    if (head == NULL) 
    {
        newNode->next = newNode;
        head = newNode;
    } else 
    {
        struct Node *temp = head;
        while (temp->next != head) 
        {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
    }
    return head;
}

CircularLL insertAfter(int x, int pos) 
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    if (head == NULL) 
    {
        newNode->next = newNode;
        head = newNode;
    } else 
    {
        struct Node *temp = head;
        for (int i = 1; i < pos - 1; i++) 
        {
            temp = temp->next;
            if (temp == head) 
            {
                printf("Invalid position. Inserting at the end.\n");
                break;
            }
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}

CircularLL deleteFromBeginning() 
{
    if (head == NULL) 
    {
        printf("Circular linked list is empty. No element to delete.\n");
        return head;
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
    return head;
}

CircularLL deleteFromEnd() 
{
    if (head == NULL) 
    {
        printf("Circular linked list is empty. No element to delete.\n");
        return head;
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
    return head;
}

CircularLL deleteAtPosition(int pos) 
{
    if (head == NULL) 
    {
        printf("Circular linked list is empty. No element to delete.\n");
        return head;
    }
    if (pos == 1) 
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
    } else 
    {
        struct Node *temp = head;
        struct Node *prev = NULL;
        int count = 1;
        while (count < pos) 
        {
            prev = temp;
            temp = temp->next;
            count++;
            if (temp == head) 
            {
                printf("Invalid position. No element found at position %d.\n", pos);
                return head;
            }
        }
        prev->next = temp->next;
        free(temp);
    }
    return head;
}

void search(int key) 
{
    if (head == NULL) 
    {
        printf("Circular linked list is empty. Cannot search for an element.\n");
        return;
    }
    struct Node *temp = head;
    int position = 1;
    int found = 0;
    do 
    {
        if (temp->data == key) 
        {
            printf("Element %d found at position %d\n", key, position);
            found = 1;
            break;
        }
        temp = temp->next;
        position++;
    } while (temp != head);
    if (!found) 
    {
        printf("Element %d not found in the circular linked list\n", key);
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
    printf("(Head)\n");
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
