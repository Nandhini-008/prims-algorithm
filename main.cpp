
#include <stdio.h>

#define V 4
#define INF 999999

void primMST(int graph[V][V]) {
    int parent[V], key[V], visited[V] = {0};
    int totalCost = 0;

    for (int i = 0; i < V; i++) {
        key[i] = INF;
        parent[i] = -1;
    }

    key[0] = 0;

    for (int count = 0; count < V; count++) {
        int min = INF, u = -1;

        for (int i = 0; i < V; i++) {
            if (!visited[i] && key[i] < min) {
                min = key[i];
                u = i;
            }
        }

        if (u == -1) {
            printf("Cities cannot all be connected.\n");
            return;
        }

        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 &&
                !visited[v] &&
                graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printf("Roads selected for Minimum Spanning Tree:\n");

    for (int i = 1; i < V; i++) {
        printf("City %d - City %d : Cost %d\n",
               parent[i] + 1, i + 1, key[i]);
        totalCost += key[i];
    }

    printf("Minimum total construction cost: %d\n",
           totalCost);
}

int main(void) {
    int graph[V][V] = {
        {0, 10, 6, 5},
        {10, 0, 0, 15},
        {6, 0, 0, 4},
        {5, 15, 4, 0}
    };

    primMST(graph);
    return 0;
}
