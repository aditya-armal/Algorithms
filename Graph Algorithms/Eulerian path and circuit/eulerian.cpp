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
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }

    void DFS(int vertex, vector<bool>& visited) {
        stack<int> stack;
        stack.push(vertex);

        while (!stack.empty()) {
            int currentVertex = stack.top();
            stack.pop();

            if (!visited[currentVertex]) {
                cout << currentVertex << " ";
                visited[currentVertex] = true;

                for (int neighbor : adj[currentVertex]) {
                    if (!visited[neighbor]) {
                        stack.push(neighbor);
                    }
                }
            }
        }
    }

    bool hasEulerianPath() {
        int oddDegreeCount = 0;
        int startVertex = 0; // Initialize the starting vertex

        for (int i = 0; i < V; i++) {
            if (adj[i].size() % 2 != 0) {
                oddDegreeCount++;
                startVertex = i;
            }
        }

        return (oddDegreeCount == 0 || oddDegreeCount == 2);
    }

    void findAndPrintEulerianPath() {
        if (!hasEulerianPath()) {
            cout << "No Eulerian path or circuit exists in the graph." << endl;
            return;
        }

        vector<bool> visited(V, false);

        // Find the starting vertex for the Eulerian path
        int startVertex = 0;
        for (int i = 0; i < V; i++) {
            if (adj[i].size() % 2 != 0) {
                startVertex = i;
                break;
            }
        }

        // Print the Eulerian path or circuit starting from the chosen vertex
        cout << "Eulerian Path or Circuit: ";
        DFS(startVertex, visited);
        cout << endl;
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

    graph.findAndPrintEulerianPath();

    return 0;
}
