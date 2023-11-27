#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 50

struct Stack 
{
    char arr[MAX];
    int top;
};

void initializeStack(struct Stack *stack) 
{
    stack->top = -1;
}

void push(struct Stack *stack, char element) 
{
    if (stack->top == MAX - 1) 
    {
        printf("Stack Overflow.\n");
        exit(EXIT_FAILURE);
    }
    stack->arr[++stack->top] = element;
}

char pop(struct Stack *stack) 
{
    if (stack->top == -1) 
    {
        printf("Stack Underflow.\n");
        exit(EXIT_FAILURE);
    }
    return stack->arr[stack->top--];
}

int isOperator(char symbol) 
{
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '%' || symbol == '^');
}

int precedence(char op) 
{
    return (op == '^') ? 3 : ((op == '*' || op == '/') || (op == '%')) ? 2 : (op == '+' || op == '-') ? 1 : 0;
}

int main() 
{
    struct Stack stack;
    initializeStack(&stack);

    char infix[MAX], postfix[MAX];
    int i = 0, j = 0;

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    while (infix[i] != '\0') 
    {
        if (isalnum(infix[i]))
        {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(')
        {
            push(&stack, infix[i]);
        }
        else if (infix[i] == ')') 
        {
            while (stack.top != -1 && stack.arr[stack.top] != '(')
            {
                postfix[j++] = pop(&stack);
            }
            pop(&stack);
        } 
        else if (isOperator(infix[i])) 
        {
            while (stack.top != -1 && precedence(stack.arr[stack.top]) >= precedence(infix[i]))
            {
                postfix[j++] = pop(&stack);
            }
            push(&stack, infix[i]);
        }
        i++;
    }

    while (stack.top != -1)
    {
        postfix[j++] = pop(&stack);
    }

    postfix[j] = '\0';

    printf("Postfix Expression: %s\n", postfix);

    return 0;
}
