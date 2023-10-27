#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
private:
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v); // Add v to u's adjacency list
    }

    void DFS(int startVertex) {
        vector<bool> visited(V, false);
        stack<int> stack;

        visited[startVertex] = true;
        stack.push(startVertex);

        while (!stack.empty()) {
            int currentVertex = stack.top();
            cout << currentVertex << " ";
            stack.pop();

            for (int neighbor : adj[currentVertex]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    stack.push(neighbor);
                }
            }
        }
    }
};

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices and edges: ";
    cin >> vertices >> edges;

    Graph graph(vertices);

    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    int startVertex;
    cout << "Enter the starting vertex for DFS: ";
    cin >> startVertex;

    cout << "Depth-First Search starting from vertex " << startVertex << ":\n";
    graph.DFS(startVertex);

    return 0;
}
