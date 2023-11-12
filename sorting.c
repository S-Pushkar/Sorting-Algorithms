#include <stdio.h>
#include <limits.h>
#include <strings.h>
#include "sorting.h"
#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

// Prints the histogram of the array along with the iteration number of the sorting process
void print_histogram(int* arr, int n, int itr) {
    printf("Iteration number: %d\n", itr);
    int max = INT_MIN;
    for(int i = 0; i < n; i++) {
        max = arr[i] > max ? arr[i] : max;
    }
    int rows = 21;
    char hist[rows][n];
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < n; j++) {
            hist[i][j] = ' ';
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= (arr[i] >= 21 ? 20 : arr[i]); j++) {
            hist[j][i] = '-';
        }
    }
    for(int i = rows - 1; i >= 0; i--) {
        for(int j = 0; j < n; j++) {
            printf("%c\t", hist[i][j]);
        }
        printf("\n");
    }
    for(int i = 0; i < n; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n\n\n");

    // Portability
    #ifdef _WIN32
        Sleep(3000);
    #else
        sleep(3);
    #endif
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Sorts the array using insertion sort and calls the print_histogram function
void insertion_sort(int* arr, int n) {
    print_histogram(arr, n, 0);
    int itr = 1;
    int i, key, j;
    for(i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        print_histogram(arr, n, itr++);
    }
}

void bubble_sort(int* arr, int n) {
    print_histogram(arr, n, 0);
    int i, j;
    int itr = 1;
    int swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                swapped = 1;
            }
        }
        print_histogram(arr, n, itr++);
        if (swapped == 0) {
            break;
        }
    }
}

void selection_sort(int* arr, int n) {
    print_histogram(arr, n, 0);
    int i, j, min_idx;
    int itr = 1;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if(min_idx != i) {
            swap(&arr[min_idx], &arr[i]);
        }
        print_histogram(arr, n, itr++);
    }
}

void heap_sort(int* arr, int n) {

}

void merge_sort(int* arr, int n) {

}

int size, itr = 1;          // Size of array and number of iterations

int partition(int* arr, int low , int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for(int j = low; j <= high; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    print_histogram(arr, size, itr++);
    return (i + 1);
}

void quick_sort(int* arr, int low, int high, int n) {
    size = n;
    int itr = 1;
    if(low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1, n);
        quick_sort(arr, pi + 1, high, n);
    }
}