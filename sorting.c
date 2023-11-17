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
        Sleep(1000);
    #else
        sleep(1);
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

int size, itr = 1;          // Size of array and number of iterations

void heapify(int* arr, int n, int i, int _size) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        // print_histogram(arr, _size, itr++);
        heapify(arr, n, largest, _size);
    }
}

void heap_sort(int* arr, int n) {
    print_histogram(arr, n, 0);
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, n);
    }
    itr = 1;
    // One by one extract an element from the heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(&arr[0], &arr[i]);
        // call max heapify on the reduced heap
        heapify(arr, i, 0, n);
        print_histogram(arr, n, itr++);
    }
}

void merge(int *arr, int l, int m, int r, int n, int *iter) { 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
  
    // Create temp arrays 
    int L[n1], R[n2]; 
  
    // Copy data to temp arrays 
    // L[] and R[] 
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
  
    // Merge the temp arrays back 
    // into arr[l..r] 
    // Initial index of first subarray 
    i = 0; 
  
    // Initial index of second subarray 
    j = 0; 
  
    // Initial index of merged subarray 
    k = l; 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    // Copy the remaining elements 
    // of L[], if there are any 
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    // Copy the remaining elements of 
    // R[], if there are any 
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
    print_histogram(arr, n, *iter);
    (*iter)++;
} 

void merge_sort(int* arr, int n, int l, int r, int *iter) {
    if (l < r) { 
        // Same as (l+r)/2, but avoids 
        // overflow for large l and h 
        int m = l + (r - l) / 2; 
  
        // Sort first and second halves 
        merge_sort(arr, n, l, m, iter); 
        merge_sort(arr, n, m + 1, r, iter);
  
        merge(arr, l, m, r, n, iter); 
    } 
}

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

void quick_sort(int* arr, int low, int high, int n, int i) {
    size = n;
    if(i == 1) {
        itr = 1;
    }
    if(low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1, n, ++i);
        quick_sort(arr, pi + 1, high, n, ++i);
    }
}