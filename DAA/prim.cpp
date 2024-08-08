#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
struct Edge {
    int to;
    int weight;
};
struct CompareEdges {
    bool operator()(const Edge& a, const Edge& b) {
        return a.weight > b.weight;
    }
};
void primMST(vector<vector<Edge>>& graph, int startVertex) {
    int numVertices = graph.size();
    vector<bool> visited(numVertices, false);
    vector<Edge> parent(numVertices);
    vector<int> key(numVertices, INT_MAX);
    priority_queue<Edge, vector<Edge>, CompareEdges> minHeap;
    key[startVertex] = 0;
    parent[startVertex].to = -1;
    minHeap.push({startVertex, 0});
    while (!minHeap.empty()) {
        int u = minHeap.top().to;
        minHeap.pop();
        visited[u] = true;
        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;

            if (!visited[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = {u, weight};
                minHeap.push({v, weight});
            }
        }
    }
    cout << "Minimum Spanning Tree:" << endl;
    for (int i = 0; i < numVertices; ++i) {
        if (parent[i].to != -1) {
            cout << "Edge: " << parent[i].to << " - " << i << " Weight: " << parent[i].weight << endl;
        }
    }
}
int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices and edges: ";
    cin >> numVertices >> numEdges;
    vector<vector<Edge>> graph(numVertices);
    cout << "Enter the edges (from, to, weight):" << endl;
    for (int i = 0; i < numEdges; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from].push_back({to, weight});
        graph[to].push_back({from, weight});
    }
    int startVertex;
    cout << "Enter the starting vertex: ";
    cin >> startVertex;
    primMST(graph, startVertex);
    return 0;
}
