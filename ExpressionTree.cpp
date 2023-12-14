#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the expression tree
struct Node {
    char data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node *createNode(char data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to evaluate the expression tree
int evaluateExpressionTree(struct Node *root) {
    if (root == NULL) {
        fprintf(stderr, "Error: Empty expression tree.\n");
        exit(EXIT_FAILURE);
    }

    // If the node is a leaf (operand), return its value
    if (root->left == NULL && root->right == NULL) {
        return root->data - '0'; // Convert character to integer
    }

    // Otherwise, evaluate left and right subtrees based on the operator
    int leftValue = evaluateExpressionTree(root->left);
    int rightValue = evaluateExpressionTree(root->right);

    // Perform the operation based on the operator
    switch (root->data) {
        case '+':
            return leftValue + rightValue;
        case '-':
            return leftValue - rightValue;
        case '*':
            return leftValue * rightValue;
        case '/':
            if (rightValue != 0) {
                return leftValue / rightValue;
            } else {
                fprintf(stderr, "Error: Division by zero.\n");
                exit(EXIT_FAILURE);
            }
        default:
            fprintf(stderr, "Error: Invalid operator %c.\n", root->data);
            exit(EXIT_FAILURE);
    }
}

// Function to free memory allocated for the expression tree
void freeExpressionTree(struct Node *root) {
    if (root != NULL) {
        freeExpressionTree(root->left);
        freeExpressionTree(root->right);
        free(root);
    }
}

int main() {
    // Construct the expression tree for the expression: (3 + 2) * 5
    struct Node *root = createNode('*');
    root->left = createNode('+');
    root->right = createNode('5');
    root->left->left = createNode('3');
    root->left->right = createNode('2');

    // Evaluate the expression tree
    int result = evaluateExpressionTree(root);
    printf("Result of the expression: %d\n", result);

    // Free memory allocated for the expression tree
    freeExpressionTree(root);

    return 0;
}
