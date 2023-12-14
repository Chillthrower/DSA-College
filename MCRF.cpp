#include <stdio.h>
#include <stdlib.h>

int main() {
    // Dynamic memory allocation using malloc
    int *arr1 = (int *)malloc(5 * sizeof(int));
    
    if (arr1 == NULL) {
        fprintf(stderr, "Memory allocation failed using malloc.\n");
        return 1;
    }

    // Initializing the array
    for (int i = 0; i < 5; i++) {
        arr1[i] = i * 2;
    }

    // Displaying the content of the dynamically allocated array
    printf("Array (allocated using malloc): ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    // Dynamic memory allocation using calloc
    int *arr2 = (int *)calloc(5, sizeof(int));

    if (arr2 == NULL) {
        fprintf(stderr, "Memory allocation failed using calloc.\n");
        free(arr1); // Free the previously allocated memory
        return 1;
    }

    // Displaying the content of the dynamically allocated array (initialized using calloc)
    printf("Array (allocated using calloc): ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    // Dynamic memory reallocation using realloc
    int *arr3 = (int *)realloc(arr1, 10 * sizeof(int));

    if (arr3 == NULL) {
        fprintf(stderr, "Memory reallocation failed using realloc.\n");
        free(arr1); // Free the previous memory block
        free(arr2); // Free the memory block allocated using calloc
        return 1;
    }

    // Initializing the additional elements in the reallocated array
    for (int i = 5; i < 10; i++) {
        arr3[i] = i * 2;
    }

    // Displaying the content of the reallocated array
    printf("Array (reallocated using realloc): ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr3[i]);
    }
    printf("\n");

    // Freeing dynamically allocated memory
    free(arr2); // Free the memory block allocated using calloc
    free(arr3); // Free the reallocated memory block

    return 0;
}
