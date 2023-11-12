#include <stdio.h>
#include "sorting.h"

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
            printf("If not, enter any other number.\n");
            int temp;
            scanf("%d", &temp);
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
                insertion_sort(arr, n);
                break;
            case 2:
                bubble_sort(arr, n);
                break;
            case 3:
                selection_sort(arr, n);
                break;
            case 4:
                heap_sort(arr, n);
                break;
            case 5:
                merge_sort(arr, n);
                break;
            case 6:
                quick_sort(arr, n);
                break;
            default:
                flag = 0;
        }
    }
    return 0;
}