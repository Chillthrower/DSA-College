#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<ctype.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;

void InsertAtBeginning(int ele)
{
    struct Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = ele;
    if (head == NULL)
    {
        newNode->next = newNode;
        head = newNode;
        printf("ele has been inserted\n");
        return;
    }
    struct Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    newNode->next = head;
    head = newNode;
    temp->next = newNode;
    printf("ele has been inserted\n");
}

void InsertAtEnd(int ele)
{
    struct Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = ele;
    if (head == NULL)
    {
        InsertAtBeginning(ele);
    }
    struct Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    newNode->next = head;
    temp->next = newNode;
    printf("ele has been inserted\n");
}

void display()
{
    if (head == NULL) 
    {
        printf("Circular linked list is empty. No element to delete.\n");
        return;
    }
    printf("entered ele : ");
    struct Node *temp = head;
    do 
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head); //Always use Do while loop
    printf(" (Head)\n");
    
}

void DeleteAtBeginning()
{
    if (head == NULL) 
    {
        printf("Circular linked list is empty. No element to delete.\n");
        return;
    }
    
    struct Node *temp = head;

    if (head->next == head) // Only one node in the list
    {
        free(head);
        head = NULL;
    } 
    else
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }

        printf("ele %d has been deleted successfully\n", head->data);
        temp->next = head->next;   // write this properly
        free(head);
        head = temp->next;
    }
}

void DeleteAtEnd()
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
    } 
    struct Node *temp = head;
    struct Node *prev = NULL;
    while (temp->next != head)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = head;
    printf("ele %d has been deleted successfully\n", temp->data);
    free(temp);
    
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