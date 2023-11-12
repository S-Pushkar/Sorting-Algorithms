#include <stdio.h>
#include <limits.h>
#include <strings.h>
#include "sorting.h"

void print_histogram(int* arr, int n) {
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
}