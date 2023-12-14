#include <stdio.h>

// Recursive binary search function
int binarySearch(int arr[], int low, int high, int key) {
    if (low <= high) {
        int mid = low + (high - low) / 2;

        // If the key is present at the middle
        if (arr[mid] == key)
            return mid;

        // If the key is smaller than the middle element, then it can only be present in the left subarray
        if (arr[mid] > key)
            return binarySearch(arr, low, mid - 1, key);

        // Else the key can only be present in the right subarray
        return binarySearch(arr, mid + 1, high, key);
    }

    // If the key is not present in the array
    return -1;
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 42, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 16;

    // Perform binary search
    int result = binarySearch(arr, 0, n - 1, key);

    if (result != -1)
        printf("Element %d found at index %d.\n", key, result);
    else
        printf("Element %d not found in the array.\n", key);

    return 0;
}
