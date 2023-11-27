#include<stdio.h>
#include<stdlib.h>

#define MAX 50

struct Stack
{
    int arr[MAX];
    int top;
};

void Intialize(struct Stack *stack)
{
    stack->top = -1;
}

void push(struct Stack *stack, int elem)
{
    if (stack->top == MAX - 1)
    {
        printf("Overflow");
    }
    else
    {
        stack->arr[++(stack->top)] = elem;
        printf("entered element successfully\n");
    }
}

void pop(struct Stack *stack)
{
    if (stack->top == -1)
    {       
        printf("Underflow");
    }
    else
    {
        printf("popped ele : %d", stack->arr[stack->top]);
        stack->arr[(stack->top)--];
        printf("\nelement deleted successfully");
    }
    
}

void display(struct Stack *stack)
{
    if(stack->top == -1)
    {
        printf("underflow");
    }
    else
    {
        printf("entered ele : ");
        for (int i = 1; i <= stack->top; i++)
        {
            printf("%d", stack->arr[i]);
        }

        printf("\n");
        
    }
}

int main()
{
    struct Stack stack;
    int choice, elem;

    do
    {
        printf("\n Main Menu \n");
        printf("press 1 to insert ele\n");
        printf("enter 2 to pop ele\n");
        printf("enter 3 to display ele\n");
        printf("enter 4 to exit element\n");
        printf("enter choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("enter the ele to be inserted : ");
                scanf("%d", &elem);
                push(&stack, elem);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                display(&stack);
                break;
            case 4:
                printf("exiting the program");
                break;
            
            default:
                printf("invalid input");
                break;
        }
    } while (choice != 4);

    return 0;
    
}