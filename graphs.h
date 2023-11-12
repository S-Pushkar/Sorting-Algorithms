#define MAX 100
typedef struct graph_node {
    int val;
    int neighbours[MAX];
} graph_node;
void topological_sort_dfs(graph_node* node);
void topological_sort_bfs(graph_node* node);