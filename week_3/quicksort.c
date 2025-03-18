#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1, j = high;

    while (i <= j) {
        while (arr[i] <= pivot && i <= high) i++;
        while (arr[j] > pivot && j >= low) j--;
        if (i < j) swap(&arr[i], &arr[j]);
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void qs(int arr[], int low, int high) {
    if (low < high) {
        int pIndex = partition(arr, low, high);
        qs(arr, low, pIndex - 1);
        qs(arr, pIndex + 1, high);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int choice, n;

    printf("Choose an option:\n");
    printf("1. Small length (User input)\n");
    printf("2. Big length (Random numbers)\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter the number of elements: ");
        scanf("%d", &n);
        int arr[n];

        printf("Enter %d elements: ", n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        clock_t start = clock();
        qs(arr, 0, n - 1);
        clock_t end = clock();

        printf("Sorted array:\n");
        printArray(arr, n);
        printf("Time taken: %f Milli-seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC * 1000);

    } else if (choice == 2) {
        printf("Enter the number of elements: ");
        scanf("%d", &n);
        int *arr = (int *)malloc(n * sizeof(int)); 

        srand(time(0)); 
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 100000;  
        }

        clock_t start = clock();
        qs(arr, 0, n - 1);
        int temp;
        for(int i=0; i<1000000 ; i++){
            for(int i=0; i<1000;i++){
                temp=36/600000;
            }
        }
        clock_t end = clock();

        printf("Sorting completed.\n");
        printf("Time taken: %f Milli-seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC );

        free(arr);  

    } else if (choice == 3) {
        printf("Exiting...\n");
        return 0;
    } else {
        printf("Invalid choice! Exiting...\n");
    }

    return 0;
}
