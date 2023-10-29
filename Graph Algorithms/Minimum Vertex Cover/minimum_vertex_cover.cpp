#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Graph {
private:
    int V; // Number of vertices
    vector<set<int>> adj; // Adjacency list

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].insert(v);
        adj[v].insert(u);
    }

    set<int> findMinimumVertexCover() {
        set<int> vertexCover;
        vector<bool> visited(V, false);

        for (int u = 0; u < V; u++) {
            if (!visited[u]) {
                for (int v : adj[u]) {
                    if (!visited[v]) {
                        visited[u] = true;
                        visited[v] = true;
                        vertexCover.insert(u);
                        vertexCover.insert(v);
                        break;
                    }
                }
            }
        }

        return vertexCover;
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

    set<int> minimumVertexCover = graph.findMinimumVertexCover();

    cout << "Minimum Vertex Cover:\n";
    for (int vertex : minimumVertexCover) {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}
