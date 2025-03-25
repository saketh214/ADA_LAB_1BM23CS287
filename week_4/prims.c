#include <stdio.h>

#define V 5

int minval(int key[], int visited[]) {
    int mini = 999, mini_index = -1; 
    for (int i = 0; i < V; i++) {
        if (!visited[i] && key[i] < mini) {
            mini = key[i];
            mini_index = i;
        }
    }
    return mini_index;
}

void printMST(int MST[], int graph[V][V]) {
    int totalWeight = 0;
    printf("\nMinimum Spanning Tree (MST):\n");
    printf("Edge   Weight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d    %d\n", MST[i], i, graph[i][MST[i]]);
        totalWeight += graph[i][MST[i]];
    }
    printf("Total weight of MST: %d\n", totalWeight);
}

void primsAlgorithm(int graph[V][V]) {
    int MST[V], key[V], visited[V] = {0};

    for (int i = 0; i < V; i++) {
        key[i] = 999;  
    }

    key[0] = 0;
    MST[0] = -1;

    for (int i = 0; i < V - 1; i++) {
        int u = minval(key, visited);

        if (u == -1) {  
            printf("Error: No valid minimum vertex found. Check input.\n");
            return;
        }

        visited[u] = 1;

        for (int j = 0; j < V; j++) {
            if (graph[u][j] && !visited[j] && graph[u][j] < key[j]) {
                MST[j] = u;
                key[j] = graph[u][j];
            }
        }
    }

    printMST(MST, graph);
}

int main() {
    int graph[V][V];

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    primsAlgorithm(graph);

    return 0;
}
