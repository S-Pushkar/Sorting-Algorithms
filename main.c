#include <stdio.h>
#include "sorting.c"
#include "graphs.h"

int main() {
    int flag = 1;
    int arr[100];
    int n;
    int isArrayUsed = 0;
    int arrayChoice = 0;
    while(flag) {
        if(isArrayUsed) {
            printf("Do you want to use the preious array?\n");
            printf("If yes, enter 1.\n");
            printf("If not, enter 2.\n");
            printf("Enter any other number to quit.\n");
            int temp;
            scanf("%d", &temp);
            if(temp != 1 && temp != 2) {
                flag = 0;
                break;
            }
            arrayChoice = temp == 1 ? 1 : 0;
        }
        if(!arrayChoice || !isArrayUsed) {
            printf("Enter the length of array to sort.(Preferrably within 20 for better visualization)\n");
            scanf("%d", &n);
            printf("Enter the elements of the array.\n");
            for(int i = 0; i < n; i++) {
                scanf("%d", (arr + i));
            }
        }
        isArrayUsed = 1;
        int cloneArray[n];
        for(int i = 0; i < n; i++) {
            cloneArray[i] = arr[i];
        }
        printf("Enter 1 to use Insertion sort.\n");
        printf("Enter 2 to use Bubble sort.\n");
        printf("Enter 3 to use Selection sort.\n");
        printf("Enter 4 to use Heap sort.\n");
        printf("Enter 5 to use Merge sort.\n");
        printf("Enter 6 to use Quick sort.\n");
        printf("Enter any other number to quit.\n");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                insertion_sort(cloneArray, n);
                break;
            case 2:
                bubble_sort(cloneArray, n);
                break;
            case 3:
                selection_sort(cloneArray, n);
                break;
            case 4:
                heap_sort(cloneArray, n);
                break;
            case 5:
                merge_sort(cloneArray, n);
                break;
            case 6:
                quick_sort(cloneArray, n);
                break;
            default:
                flag = 0;
        }
    }
    return 0;
}