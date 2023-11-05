
//LinkedList
#include <stdio.h>
#include <stdlib.h>

struct LinkedList
{
    int data;
    struct LinkedList *next;
};

struct LinkedList *head;

void beginsert(int x)
{
    struct LinkedList *temp = (struct LinkedList *)malloc(sizeof(struct LinkedList));
    temp->data = x;
    temp->next = head;
    head = temp;
}

void randominsert(int x, int pos)
{
    struct LinkedList *temp1 = (struct LinkedList *)malloc(sizeof(struct LinkedList));
    temp1->data = x;
    temp1->next = NULL;

    if (pos == 1)
    {
        temp1->next = head;
        head = temp1;
        return;
    }

    struct LinkedList *temp2 = head;
    for (int i = 0; i < pos - 2; i++)
    {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
}

void lastinsert(int x)
{
    struct LinkedList *newNode = (struct LinkedList *)malloc(sizeof(struct LinkedList));
    newNode->data = x;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct LinkedList *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void begin_del()
{
    if (head == NULL)
    {
        printf("Linked list is empty. No element to delete.\n");
        return;
    }

    struct LinkedList *temp = head;
    head = head->next;
    free(temp);
}

void last_del()

{
    if (head == NULL)
    {
        printf("Linked list is empty. No element to delete.\n");
        return;
    }

    struct LinkedList *temp = head;
    struct LinkedList *prev = NULL;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    free(temp);
    if (prev != NULL)
    {
        prev->next = NULL;
    }
    else
    {
        head = NULL;
    }
}

void randomdelete(int pos)
{
    if (head == NULL)
    {
        printf("Linked list is empty. No element to delete.\n");
        return;
    }

    if (pos == 1)
    {
        // struct LinkedList *temp = head;
        // head = head->next;
        // free(temp);0
        begin_del();
        printf("Element at position %d deleted successfully.\n", pos);
        return;
    }

    if (pos > 1)
    {
        struct LinkedList *temp = head;
        struct LinkedList *prev = NULL;
        int count = 1;

        while (temp != NULL && count < pos)
        {
            prev = temp;
            temp = temp->next;
            count++;
        }

        if (temp == NULL)
        {
            printf("Invalid position. No element found at position %d.\n", pos);
            return;
        }

        prev->next = temp->next;
        free(temp);
        printf("Element at position %d deleted successfully.\n", pos);
    }
    else
    {
        printf("Invalid position. Please enter a valid position to delete.\n");
    }
}

void search(int key)
{
    struct LinkedList *temp = head;
    int position = 1;
    int found = 0;

    while (temp->next != NULL)
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
        printf("Element %d not found in the linked list\n", key);
    }
}

void display()
{
    struct LinkedList *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice = 0, x, n;
    while (choice != 9)
    {
        printf("\n*********Main Menu*********\n");
        printf("Choose one option from the following list ...\n");
        printf("===============================================\n");
        printf("1. Insert at the beginning\n2. Insert at last\n3. Insert at any random location\n4. Delete from the beginning\n5. Delete from last\n6. Delete node after specified location\n7. Search for an element\n8. Show\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d", &x);
            beginsert(x);
            break;
        case 2:
            printf("Enter the element to be inserted at the end: ");
            scanf("%d", &x);
            lastinsert(x);
            break;
        case 3:
            printf("Enter the element to be inserted: ");
            scanf("%d", &x);
            printf("Enter the position: ");
            scanf("%d", &n);
            randominsert(x, n);
            break;
        case 4:
            begin_del();
            break;
        case 5:
            last_del();
            break;
        case 6:
            printf("Enter the position: ");
            scanf("%d", &n);
            randomdelete(n);
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
