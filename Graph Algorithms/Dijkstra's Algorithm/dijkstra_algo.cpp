#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int INF = 1e9; // A very large value representing infinity

class Graph {
private:
    int V; // Number of vertices
    vector<vector<pair<int, int>> > adj; // Adjacency list (vertex, weight)

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w}); // Add edge from u to v with weight w
    }

    void dijkstra(int source) {
        vector<int> dist(V, INF); // Initialize distances as infinity
        dist[source] = 0; // Distance from source to itself is 0

        set<pair<int, int>> pq; // Priority queue to select the vertex with the smallest distance

        pq.insert({0, source});

        while (!pq.empty()) {
            int u = pq.begin()->second; // Get the vertex with the smallest distance
            pq.erase(pq.begin());

            for (pair<int, int> edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (dist[u] + weight < dist[v]) {
                    pq.erase({dist[v], v});
                    dist[v] = dist[u] + weight;
                    pq.insert({dist[v], v});
                }
            }
        }

        cout << "Shortest distances from source vertex " << source << ":\n";
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << ": " << dist[i] << endl;
        }
    }
};

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices and edges: ";
    cin >> vertices >> edges;

    Graph graph(vertices);

    cout << "Enter the edges and their weights (u v w):\n";
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph.addEdge(u, v, w);
    }

    int source;
    cout << "Enter the source vertex for Dijkstra's algorithm: ";
    cin >> source;

    graph.dijkstra(source);

    return 0;
}
