#include <stdio.h>
#include "sorting.h"

int main() {
    int flag = 1;
    while(flag) {
        printf("Enter the length of array to sort.(Preferrably within 20 for better visualization)\n");
        int n;
        scanf("%d", &n);
        printf("Enter the elements of the array.\n");
        int arr[n];
        for(int i = 0; i < n; i++) {
            scanf("%d", (arr + i));
        }
        printf("Enter 1 to use Insertion sort.\n");
        printf("Enter 2 to use Bubble sort.\n");
        printf("Enter 3 to use Selection sort.\n");
        printf("Enter 4 to use Heap sort.\n");
        printf("Enter 5 to use Merge sort.\n");
        printf("Enter 6 to use Quick sort.\n");
        printf("Enter any other number to quit");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1:

                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            case 5:

                break;
            case 6:

                break;
            default:
                flag = 0;
        }
    }
    return 0;
}