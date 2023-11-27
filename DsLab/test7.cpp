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

void InsertElement(int ele)
{
    struct Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = ele;
    newNode->next = head;
    head = newNode;

    printf("ele added\n");
}

void DisplayAndCount()
{
    int count = 0;
    printf("Singly Linked List Status:\n");
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
        count++;
    }

    printf("\nNumber of nodes: %d\n", count);
    
}

void push(int ele)
{
    InsertElement(ele);
}

void pop()
{
    if (head == NULL)
    {
        printf("underflow");
    }
    struct Node *temp = head;
    head = head->next;
    printf("ele %d has been deleted successfully\n", temp->data);
    free(temp);
    
}

int main()
{
    int choice, ele;

    do
    {
        printf("\n Main Menu \n");
        printf("press 1 to Insert Element\n");
        printf("press 2 to Display Element\n");    
        printf("press 3 to Demonstrate Stack\n");
        printf("press 4 to Exit\n");  
        printf("Select a choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the element to be inserted : ");
                scanf("%d", &ele);
                InsertElement(ele);
                break;
            case 2:
                DisplayAndCount();
                break;
            case 3:
                printf("\nMain menu for Stack implementation\n");
                printf("enter 1 to push ele\n");
                printf("enter 2 to pop\n");
                printf("Enter Choice :\n");
                scanf("%d", &choice);

                switch (choice)
                {
                    case 1:
                        printf("enter the ele to be inserted");
                        scanf("%d", &ele);
                        push(ele);
                        break;
                    case 2:
                        pop();
                        
                    default:
                        printf("Invalid choice");
                        break;
                }
                break;
            case 4:
                printf("Existing the program\n");
                break;
            
            default:
                printf("invalid choice");
                break;
        }  
    } while (choice != 4);

    return 0;
    
}