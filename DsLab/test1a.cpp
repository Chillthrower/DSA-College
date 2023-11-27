#include<stdio.h>
#include<stdlib.h>

#define MAX 50

void InsertElement(int arr[], int *n, int pos, int elem)
{
    if (pos < 1 || pos < *n + 1)
    {
        printf("invalid position\n");
    }
    else
    {
        for (int i = *n; i >= pos; i--)
        {
            arr[i] = arr[i - 1];
        }

        arr[pos - 1] = elem;
        (*n)++;
        printf("element added successfully\n");
        
    }
    
}

void display(int arr[], int *n)
{
    if (n == 0)
    {
        printf("array is empty \n");
    }
    else
    {
        for (int i = 0; i < *n; i++)
        {
            printf("%d ", arr[i]);
        }

        printf("\n");
        
    }
    
}

void DeleteElement(int arr[], int pos, int *n)
{
    if (pos < 1 || pos > *n)
    {
        printf("invalid position\n");
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

int main()
{
    int arr[MAX];
    int n = 0;
    int choice, elem, pos;

    do
    {
        printf("\nDisplay Menu\n");
        printf("Press 1 to insert element : \n");  
        printf("Press 2 to display element : \n");    
        printf("Press 3 to delete element : \n");    
        printf("Press 4 to exit element : \n");

        printf("enter tour choice : ");
        scanf("%d", &choice);    
         switch (choice)
         {
            case 1:
                printf("enter the ele to be inserted : ");
                scanf("%d", &pos);
                printf("enter the pos where the ele should be inserted : ");
                scanf("%d", &elem);
                InsertElement(arr, &n, pos, elem);
                break;

            case 2:
                printf("entered ele : ");
                display(arr, &n);
                break;
            
            case 3:
                printf("enter the pos to be deleted : ");
                scanf("%d", &pos);
                DeleteElement(arr, pos, &n);
            
            default:
                break;
         }
    } 
    while (choice != 4);
    
    
}