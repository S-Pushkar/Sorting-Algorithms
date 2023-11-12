// Run mingw32-make -f make.mk to create a.exe

#include <stdio.h>
#include "sorting.h"
#include "graphs.h"

int main() {
    int flag = 1;
    int arr[100];
    int n;
    int isArrayUsed = 0;
    int arrayChoice = 0;

    int graph[100][2];
    int edges;
    int isGraphUsed = 0;
    int graphChoice = 0;
    int graphOrArray = 0; // 1 for array and 2 for graph
    while(flag) {
        printf("Enter 1 for array operations.\n");
        printf("Enter 2 for graph operations.\n");
        printf("Enter any other number to quit.\n");
        scanf("%d", &graphOrArray);
        if(graphOrArray != 1 && graphOrArray != 2) {
            flag = 0;
            break;
        }
        if(isArrayUsed && graphOrArray == 1) {
            printf("Do you want to use the previous array?\n");
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
        if(isGraphUsed && graphOrArray == 2) {
            printf("Do you want to use the previous graph?\n");
            printf("If yes, enter 1.\n");
            printf("If not, enter 2.\n");
            printf("Enter any other number to quit.\n");
            int temp;
            scanf("%d", &temp);
            if(temp != 1 && temp != 2 && temp != 3) {
                flag = 0;
                break;
            }
            graphChoice = temp == 1 ? 1 : 0;
        }
        if(graphOrArray == 1 && (!arrayChoice || !isArrayUsed)) {
            printf("Enter the length of array to sort.(Preferrably within 20 for better visualization)\n");
            scanf("%d", &n);
            printf("Enter the elements of the array.\n");
            for(int i = 0; i < n; i++) {
                scanf("%d", (arr + i));
            }
            isArrayUsed = 1;
        }
        if(graphOrArray == 2 && (!graphChoice || !isGraphUsed)) {
            printf("Enter the number of edges present in graph.\n");
            scanf("%d", &edges);
            printf("Enter the edges of the graph.\n");
            for(int i = 0; i < edges; i++) {
                scanf("%d %d", &(graph[i][0]), &(graph[i][1]));
            }
            isGraphUsed = 1;
        }
        if(graphOrArray == 1) {
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
                    print_histogram(cloneArray, n, 0);
                    quick_sort(cloneArray, 0, n - 1, n);
                    break;
                default:
                    flag = 0;
            }
        }
        else if(graphOrArray == 2) {
            int cloneGraph[edges][2];
            for(int i = 0; i < edges; i++) {
                cloneGraph[i][0] = graph[i][0];
                cloneGraph[i][1] = graph[i][1];
            }
            printf("Enter 1 for topological sort using DFS.\n");
            printf("Enter 2 for topological sort using BFS.\n");
            printf("Enter any other number to quit.\n");
            int choice;
            scanf("%d", &choice);
            switch(choice) {
                case 1:
                    topological_sort_dfs(cloneGraph, edges);
                    break;
                case 2:
                    topological_sort_bfs(cloneGraph, edges);
                    break;
                default:
                    flag = 0;
            }
        }
    }
    return 0;
}