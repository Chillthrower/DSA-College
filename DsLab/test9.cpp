#include<stdio.h>
#include<stdlib.h>  
#include<cmath>
#include<ctype.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head = NULL;

void InsertAtBeginning(int ele)
{
    struct Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = ele;
    newNode->next = head;
    newNode->prev = NULL;
    if (head != NULL)
    {
        head->prev = newNode;
    }
    
    head = newNode;
}

void InsertAtEnd(int ele)
{
    struct Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = ele;
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
    newNode->prev = temp;
    newNode->next = NULL;
    temp->next = newNode;
}

void DeleteAtBeginning()
{
    if (head == NULL) 
    {
        printf("Doubly linked list is empty. No element to delete.\n");
        return;
    }
    struct Node *temp = head;
    head = temp->next;
    if(temp->next != NULL)
    {
        temp->next->prev = NULL;
    }
    free(temp);
    
}

void DeleteAtEnd()
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
    if (head == NULL) 
    {
        printf("Doubly linked list is empty. No element to delete.\n");
        return;
    }
    struct Node *temp = head;
    while(temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice, ele;
    do
    {
        printf("\n Main Menu \n");
        printf("Enter 1 to insert at beginning\n");
        printf("Enter 2 to insert at End\n");
        printf("Enter 3 to Delete at beginning\n");
        printf("Enter 4 to Delete at End\n");
        printf("Enter 5 to Display\n");
        printf("Enter 6 to Exit\n");
        printf("Enter your Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("enter the ele to be inserted : ");
            scanf("%d", &ele);
            InsertAtBeginning(ele);
            break;
        case 2:
            printf("enter the ele to be inserted in the end : ");
            scanf("%d", &ele);
            InsertAtEnd(ele);
            break;
        case 3:
            DeleteAtBeginning();
            break;
        case 4:
            DeleteAtEnd();
            break;
        case 5:
            display();
            break;
        
        
        default:
            printf("invalid input");
            break;
        }

    } while (choice != 6);

    return 0;
    
}