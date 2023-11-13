#include <stdio.h>
#include <limits.h>
#include <strings.h>
#include "graphs.h"
#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

void build_adj(graph_node* adj, int graph[][2], int n) {
    for(int i = 0; i < MAX; i++) {
        memset(adj[i].neighbours, 0, sizeof(adj[i].neighbours));
        adj[i].size_neighbours = 0;
    }
    for(int i = 0; i < n; i++) {
        int from_edge = graph[i][0];
        int to_edge = graph[i][1];
        adj[from_edge].val = from_edge;
        adj[from_edge].neighbours[adj[from_edge].size_neighbours++] = to_edge;
    }
}

void topological_sort_dfs(int graph[][2], int n) {
      graph_node adj[MAX];
      build_adj(adj, graph, n);
      // This function is incomplete. I'll finish it later.
}

void topological_sort_bfs(int graph[][2], int n) {
       
}