#include <iostream>
#include <vector>
#include <climits>
using namespace std;
// Number of vertices in the graph
#define V 4
// Function to implement the Floyd-Warshall algorithm
void floydWarshall(int graph[V][V]) {
    // Create a 2D array dist[][] to store the shortest distances between every pair of vertices
    int dist[V][V];
    // Initialize the distance matrix with the input graph
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }
    // Calculate shortest paths for all pairs of vertices
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                // If vertex k is on the shortest path from i to j, update the value of dist[i][j]
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && (dist[i][k] + dist[k][j] < dist[i][j])) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    // Print the shortest distances
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INT_MAX) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
}
int main() {
    // Example input graph with weights (INF represents infinity)
    int graph[V][V] = {
        {0, 3, INT_MAX, 5},
        {2, 0, INT_MAX, INT_MAX},
        {INT_MAX, 7, 0, 1},
        {6, INT_MAX, INT_MAX, 0}
    };
    // Find and print all-pairs shortest paths
    floydWarshall(graph);
    return 0;
}
