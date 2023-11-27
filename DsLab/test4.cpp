#include<stdio.h>
#include<stdlib.h>  
#include<ctype.h>
#include<string.h>
#include<cmath>
#define MAX 50

struct Stack
{
    int arr[MAX];
    int top;
};

void push(struct Stack *stack, int ele)
{
    if (stack->top == MAX - 1)
    {
        printf("Stack is full");
        exit(EXIT_FAILURE);
    }
    stack->arr[++(stack->top)] = ele;
}

int pop(struct Stack *stack)
{
    if (stack->top == -1)
    {
        printf("Stack is empty");
    }
    return stack->arr[stack->top--];
    
}

int evaluatePostfix(char *ip)
{
    struct Stack stack;
    stack.top = -1;

    char PostFix[MAX], Infix[MAX];
    int j = 0, i = 0;

    for (int i = 0; ip[i]; i++)
    {
        if (isdigit(ip[i]))
        {
            push(&stack, ip[i] - '0');
        }
        else
        {
            int val1 = pop(&stack);
            int val2 = pop(&stack);
            switch (ip[i]) 
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
    printf("enter infix operation : ");
    scanf("%s", exp);
    printf("Answer : %d", evaluatePostfix(exp));

    return 0;
}