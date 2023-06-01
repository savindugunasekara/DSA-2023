#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 6 // number of vertices

// function to find the minimum distance value

int minDistance(int distance[], bool SPTset[])
{
    int min = INT_MAX, minimumIndex;

    for (int v = 0; v < V; v++)
        if (SPTset[v] == false && distance[v] <= min)
            min = distance[v], minimumIndex = v;

    return minimumIndex;
}
//print the distance array

void printSolution(int distance[], int n)
{
    printf("Vertex   Distance from Source(Time taken)\n");
    for (int i = 0; i < V; i++)
        printf("%d -------> %d\n", i, distance[i]);
}
// implement Dijkstra's algorithm for the graph
void dijkstra(int graph[V][V], int source)
{
    int distance[V]; // holds the shortest distance from V to source
    bool SPTset[V];

    for (int i = 0; i < V; i++)  // initialize all distances as infinite at the begining
        distance[i] = INT_MAX, SPTset[i] = false;

    distance[source] = 0;  // distance to itself is zero

    for (int count = 0; count < V - 1; count++) { // pick the minimum distance vertex from the vertices set
        int u = minDistance(distance, SPTset);
        SPTset[u] = true;   //establish the picked vertiex as already processed

        for (int v = 0; v < V; v++)
            if (!SPTset[v] && graph[u][v] && distance[u] != INT_MAX && distance[u] + graph[u][v] < distance[v])
                distance[v] = distance[u] + graph[u][v];
    }

    printSolution(distance, V);
}

int main()
{
    int graph[V][V] = {{0, 10, 0, 0, 15, 5},
                       {10, 0, 10, 30, 0, 0},
                       {0, 10, 0, 12, 5, 0},
                       {0, 30, 12, 0, 0, 20},
                       {15, 0, 5, 0, 0, 0},
                       {5, 0, 0, 20, 0, 0}};
    int source_node = 5;
    printf("Source is %d\n", source_node);
    dijkstra(graph, source_node);

    return 0;
}
