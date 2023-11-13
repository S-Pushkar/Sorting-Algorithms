#define MAX 101
typedef struct graph_node {
    int val;
    int neighbours[MAX];
    int size_neighbours;      // 0 means there are no neighbours & 1 means there's 1 neighbour
} graph_node;
void topological_sort_dfs(int graph[][2], int n);
void topological_sort_bfs(int graph[][2], int n);