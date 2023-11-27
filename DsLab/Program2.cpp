#include <stdio.h>

#define MAX 5

struct Stack 
{
    int arr[MAX];
    int top;
};

void initializeStack(struct Stack *stack) 
{
    stack->top = -1;
}

void push(struct Stack *stack, int element) 
{
    if (stack->top == MAX - 1) 
    {
        printf("Stack Overflow. Cannot push element.\n");
    } 
    else 
    {
        stack->arr[++(stack->top)] = element;
        printf("Element pushed successfully.\n");
    }
}

int pop(struct Stack *stack) 
{
    if (stack->top == -1) 
    {
        printf("Stack Underflow. Cannot pop element.\n");
        return -1;
    } 
    else 
    {
        return stack->arr[(stack->top)--];
    }
}

void displayStatus(struct Stack *stack) 
{
    if (stack->top == -1) 
    {
        printf("Stack is empty.\n");
    } 
    else if (stack->top == MAX - 1) 
    {
        printf("Stack is full.\n");
    } 
    else 
    {
        printf("Stack is not empty. Elements present: %d\n", stack->top + 1);
    }
}

void displayStack(struct Stack *stack) 
{
    if (stack->top == -1) 
    {
        printf("Stack is empty.\n");
    } 
    else 
    {
        printf("Stack elements: ");
        for (int i = 0; i <= stack->top; i++) 
        {
            printf("%d ", stack->arr[i]);
        }
        printf("\n");
    }
}

int main() 
{
    struct Stack stack;
    initializeStack(&stack);

    int choice, element;

    do 
    {
        // Display menu
        printf("\nMenu:\n");
        printf("1. Push Element\n");
        printf("2. Pop Element\n");
        printf("3. Display Stack Status\n");
        printf("4. Display Stack Elements\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &element);
                push(&stack, element);
                break;

            case 2:
                element = pop(&stack);
                if (element != -1) 
                {
                    printf("Popped Element: %d\n", element);
                }
                break;

            case 3:
                displayStatus(&stack);
                break;

            case 4:
                displayStack(&stack);
                break;

            case 5:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}
