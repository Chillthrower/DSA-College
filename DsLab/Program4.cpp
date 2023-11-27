#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 50

struct Stack 
{
    int top;
    int arr[MAX];
};

void push(struct Stack* stack, int operand) 
{
    if (stack->top == MAX - 1) 
    {
        printf("Stack Overflow. Cannot push element.\n");
        exit(EXIT_FAILURE);
    } 
    else 
    {
        stack->arr[++stack->top] = operand;
    }
}

int pop(struct Stack* stack) 
{
    if (stack->top == -1) 
    {
        printf("Stack Underflow. Cannot pop element.\n");
        exit(EXIT_FAILURE);
    } 
    else 
    {
        return stack->arr[stack->top--];
    }
}

int evaluatePostfix(char* exp) 
{
    struct Stack stack;
    stack.top = -1;

    for (int i = 0; exp[i]; ++i) 
    {
        if (isdigit(exp[i]))
            push(&stack, exp[i] - '0');
        
        else 
        {
            int val1 = pop(&stack);
            int val2 = pop(&stack);
            switch (exp[i]) 
            {
                case '+': 
                    push(&stack, val2 + val1); 
                    break;
                case '-': 
                    push(&stack, val2 - val1); 
                    break;
                case '*': 
                    push(&stack, val2 * val1); 
                    break;
                case '/': 
                    push(&stack, val2 / val1); 
                    break;
                case '%': 
                    push(&stack, val2 % val1); 
                    break;
                case '^': 
                    push(&stack, (int)pow(val2, val1)); 
                    break;
            }
        }
    }

    return pop(&stack);
}

int main() 
{
    char exp[MAX];
    
    printf("Enter the postfix expression: ");
    scanf("%s", exp);
    
    printf("Result of the postfix expression: %d\n", evaluatePostfix(exp));

    return 0;
}
