#include<stdio.h>
#include<stdlib.h>
#include<cmath>  // Always use these libraries
#include<ctype.h>
#define MAX 50

struct Stack
{
    char arr[MAX];
    int top;
};

void Intialize(struct Stack *stack)
{  
    stack->top = -1;
}

void push(struct Stack *stack, int element)
{
    if (stack->top == MAX - 1)
    {
        printf("Overflow");
        exit(EXIT_FAILURE);
    }
    else
    {
        stack->arr[++(stack->top)] = element;
    }
}

char pop(struct Stack *stack)
{
    if (stack->top == -1)
    {
        printf("Underflow");
        exit(EXIT_FAILURE);
    }
    else
    {
        return stack->arr[stack->top--];
    }
}

int isOperator(char symbol)
{
    return (symbol == '+' || symbol == '-' || symbol == '/' || symbol == '*' || symbol == '%' || symbol == '^');
}

int prec(char symbol)
{
    return (symbol == '^') ? 3 : ((symbol == '*' || symbol == '/') || (symbol == '%')) ? 2 : (symbol == '+' || symbol == '-') ? 1 : 0;
}

int main()
{
    struct Stack stack;
    stack.top = -1;
    
    char Postfix[MAX], Infix[MAX];
    int j = 0, i = 0;

    printf("enter yout input : ");
    scanf("%s", Infix);  // for inputing dont use &

    while (Infix[i] != '\0')
    {
        if (isalnum(Infix[i]))
        {
            Postfix[j++] = Infix[i];
        }
        else if(Infix[i] == '(')
        {
            Postfix[j++] = Infix[i];
        }
        else if(Infix[i] == ')')
        {
            while (stack.top != -1 && stack.arr[stack.top] != '(')
            {
                Postfix[j++] = pop(&stack);
            }
            pop(&stack);
        }
        else if (isOperator(Infix[i]))
        {   
            while (stack.top != -1 && prec(stack.arr[stack.top]) >= prec(Infix[i]))
            {
                Postfix[j++] = pop(&stack);
            }
            push(&stack, Infix[i]);
        }
        i++;
        
    }

    while (stack.top != -1)
    {
        Postfix[j++] = pop(&stack);
    }

    Postfix[j] = '\0';

    printf("answer : %s", Postfix);

    return 0;
    
    
}