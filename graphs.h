#define MAX 101
typedef struct graph_node {
    int val;
    int neighbours[MAX];
    int size_neighbours;      // count of neighbours | 0 means there are no neighbours
} graph_node;
void topological_sort_dfs(int graph[][2], int n);
void topological_sort_bfs(int graph[][2], int n);