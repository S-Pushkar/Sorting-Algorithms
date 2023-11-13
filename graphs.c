#include <stdio.h>
#include <limits.h>
#include <strings.h>
#include "graphs.h"
#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};
 
// function to create a queue
// of given capacity.
// It initializes size of queue as 0
struct Queue* createQueue(unsigned capacity)
{
    struct Queue* queue = (struct Queue*)malloc(
        sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
 
    // This is important, see the enqueue
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(
        queue->capacity * sizeof(int));
    return queue;
}
 
// Queue is full when size becomes
// equal to the capacity
int isFull(struct Queue* queue)
{
    return (queue->size == queue->capacity);
}
 
// Queue is empty when size is 0
int isEmpty(struct Queue* queue)
{
    return (queue->size == 0);
}
 
// Function to add an item to the queue.
// It changes rear and size
void enqueue(struct Queue* queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1)
                  % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}
 
// Function to remove an item from queue.
// It changes front and size
int dequeue(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1)
                   % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}
 
// Function to get front of queue
int front(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}
 
// Function to get rear of queue
int rear(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}

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

int build_Indegree(int indeg[], int graph[][2], int n) {
    int countOfNodes = 0;

    for (int i = 0; i < n; i++) {
        countOfNodes += (indeg[graph[i][0]] == -1) + (indeg[graph[i][1]] == -1);
        indeg[graph[i][0]] = 0;
        indeg[graph[i][1]] = 0;
    }

    for (int i = 0; i < n; i++) {
        indeg[graph[i][1]]++;
    }

    return countOfNodes;
}

void topological_sort_dfs(int graph[][2], int n) {
      graph_node adj[MAX];
      build_adj(adj, graph, n);
      // Pushkar Drinks :)
}

void topological_sort_bfs(int graph[][2], int n) {
    graph_node adj[MAX];
    int indeg[MAX];

    memset(indeg, -1, sizeof(indeg));

    build_adj(adj, graph, n);
    int countOfNodes = build_Indegree(indeg, graph, n);

    struct Queue* q = createQueue(101);
    for (int i = 0; i < MAX; i++) {
        if (indeg[i] == 0) {
            enqueue(q, i);
        }
    }

    int result[MAX];
    memset(result, -1, sizeof(result));
    int ptr = 0;


    while (!isEmpty(q)) {
        int cur = front(q);
        dequeue(q);

        result[ptr++] = cur;

        for (int i = 0; i < adj[cur].size_neighbours; i++) {
            int neighbour = adj[cur].neighbours[i];
            indeg[neighbour]--;

            if (indeg[neighbour] == 0) {
                enqueue(q, neighbour);
            }
        }
    }

    if (ptr != countOfNodes) {
        printf("Topological sort is not possible because there is a cycle in the graph.");
        return;
    }

    printf("Topological Sort: ");
    for (int i = 0; i < ptr; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}   