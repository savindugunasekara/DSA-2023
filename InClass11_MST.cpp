#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Graph {
    int V;                      // number of vertices
    vector<vector<int>> matrix; // adjacency matrix

public:
    Graph(int V) {
        this->V = V;
        matrix.resize(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v, int weight) {
        matrix[u][v] = weight;
        matrix[v][u] = weight;
    }

    void primMST() {
        vector<int> key(V, INT_MAX);    // Key values used to pick minimum weight edge
        vector<int> parent(V, -1);      // Array to store constructed MST
        vector<bool> mstSet(V, false);  // Set to track vertices included in MST

        // Start with the first vertex
        key[0] = 0;
        parent[0] = -1;

        // Construct MST with V-1 vertices
        for (int count = 0; count < V - 1; count++) {
            int u = minKey(key, mstSet);
            mstSet[u] = true;

            // Update key values and parent index for adjacent vertices of u
            for (int v = 0; v < V; v++) {
                if (matrix[u][v] != 0 && mstSet[v] == false && matrix[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = matrix[u][v];
                }
            }
        }

        // Print the MST
        cout << "Edge\tWeight\n";
        for (int i = 1; i < V; i++) {
            cout << parent[i] << " - " << i << "\t" << matrix[i][parent[i]] << endl;
        }
    }

    int minKey(const vector<int>& key, const vector<bool>& mstSet) {
        int minKey = INT_MAX;
        int minIndex;

        for (int v = 0; v < V; v++) {
            if (mstSet[v] == false && key[v] < minKey) {
                minKey = key[v];
                minIndex = v;
            }
        }

        return minIndex;
    }
};

int main() {
    int V = 6;  // number of vertices
    Graph g(V); // create a graph with 6 vertices

    vector<vector<int>> adjMatrix = {
        {0, 3, 0, 0, 0, 1},
        {3, 0, 2, 1, 10, 0},
        {0, 2, 0, 3, 0, 5},
        {0, 1, 3, 0, 5, 0},
        {0, 10, 0, 5, 0, 4},
        {1, 0, 5, 0, 4, 0}
    };

    // Construct the graph using the adjacency matrix
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (adjMatrix[i][j] != 0) {
                g.addEdge(i, j, adjMatrix[i][j]);
            }
        }
    }

    // Find and print the minimum spanning tree using Prim's algorithm
    g.primMST();   
    } 
