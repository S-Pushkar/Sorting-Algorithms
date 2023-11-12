#define MAX 100
typedef struct graph_node {
    int val;
    int neighbours[MAX];
} graph_node;
void topological_sort_dfs(int graph[][2], int n);
void topological_sort_bfs(int graph[][2], int n);