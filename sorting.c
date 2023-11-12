#include <stdio.h>
#include <limits.h>
#include <strings.h>
#include <windows.h>
#include "sorting.h"

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
    Sleep(3000);
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

}

void selection_sort(int* arr, int n) {

}

void heap_sort(int* arr, int n) {

}

void merge_sort(int* arr, int n) {

}

void quick_sort(int* arr, int n) {

}