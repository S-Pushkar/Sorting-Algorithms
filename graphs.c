#include <stdio.h>
#include <limits.h>
#include <strings.h>
#include "graphs.h"
#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

void topological_sort_dfs(int graph[][2], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d %d\n", graph[i][0], graph[i][1]);
    }
    for(int i = 0; i < n; i++) {
        graph[i][0] = -1;
        graph[i][1] = -1;
    }
}

void topological_sort_bfs(int graph[][2], int n) {
    printf("Something.........\n");    
}