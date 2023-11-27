#include <stdio.h>

void insertElement(int arr[], int *n, int elem, int pos) 
{
    if (pos < 1 || pos > *n + 1) 
    {
        printf("Invalid position. Insertion failed.\n");
    } 
    else 
    {
        for (int i = *n; i >= pos; i--) 
        {
            arr[i] = arr[i - 1];
        }
        arr[pos - 1] = elem;
        (*n)++;
        printf("Element inserted successfully.\n");
    }
}

void deleteElement(int arr[], int *n, int pos) 
{
    if (pos < 1 || pos > *n) 
    {
        printf("Invalid position. Deletion failed.\n");
    } 
    else 
    {
        for (int i = pos - 1; i < *n - 1; i++) 
        {
            arr[i] = arr[i + 1];
        }
        (*n)--;
        printf("Element deleted successfully.\n");
    }
}

void displayArray(int arr[], int n) 
{
    if (n == 0) 
    {
        printf("Array is empty.\n");
    } 
    else 
    {
        printf("Array elements: ");
        for (int i = 0; i < n; i++) 
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int main() 
{
    int arr[100];
    int n = 0;
    int choice, elem, pos;

    do 
    {
        printf("\nMenu:\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Display Array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &elem);
                printf("Enter the position to insert: ");
                scanf("%d", &pos);
                insertElement(arr, &n, elem, pos);
                break;

            case 2:
                printf("Enter the position to delete: ");
                scanf("%d", &pos);
                deleteElement(arr, &n, pos);
                break;

            case 3:
                displayArray(arr, n);
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
