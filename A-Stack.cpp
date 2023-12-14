#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Function to initialize an empty stack
void initialize(int arr[], int top) {
    arr[top] = -1;
}

// Function to push an element onto the stack
void push(int arr[], int *top, int value) {
    if (*top == MAX_SIZE - 1) {
        printf("Stack overflow. Cannot push %d.\n", value);
    } else {
        arr[++(*top)] = value;
        printf("%d pushed to the stack.\n", value);
    }
}

// Function to pop an element from the stack
void pop(int arr[], int *top) {
    if (*top == -1) {
        printf("Stack underflow. Cannot pop from an empty stack.\n");
    } else {
        printf("Popped element: %d\n", arr[(*top)--]);
    }
}

// Function to get the top element of the stack without popping it
void peek(int arr[], int top) {
    if (top == -1) {
        printf("The stack is empty.\n");
    } else {
        printf("Top element of the stack: %d\n", arr[top]);
    }
}

// Function to display all elements in the stack
void display(int arr[], int top) {
    if (top == -1) {
        printf("The stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= top; ++i) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

// Driver program to test the stack implementation
int main() {
    int stack[MAX_SIZE];
    int top = -1;
    initialize(stack, top);

    push(stack, &top, 10);
    push(stack, &top, 20);
    push(stack, &top, 30);

    display(stack, top);

    peek(stack, top);
    pop(stack, &top);
    pop(stack, &top);

    display(stack, top);

    return 0;
}
