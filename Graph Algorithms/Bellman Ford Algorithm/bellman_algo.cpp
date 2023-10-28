#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9; // A very large value representing infinity

struct Edge {
    int source, destination, weight;
};

class Graph {
private:
    int V; // Number of vertices
    int E; // Number of edges
    vector<Edge> edges;

public:
    Graph(int vertices, int edgesCount) {
        V = vertices;
        E = edgesCount;
        edges.resize(E);
    }

    void addEdge(int u, int v, int w, int edgeIndex) {
        edges[edgeIndex] = {u, v, w};
    }

    void bellmanFord(int source) {
        vector<int> dist(V, INF);
        dist[source] = 0;

        for (int i = 1; i <= V - 1; i++) {
            for (int j = 0; j < E; j++) {
                int u = edges[j].source;
                int v = edges[j].destination;
                int weight = edges[j].weight;

                if (dist[u] != INF && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }

        // Check for negative cycles
        for (int j = 0; j < E; j++) {
            int u = edges[j].source;
            int v = edges[j].destination;
            int weight = edges[j].weight;

            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                cout << "Graph contains a negative cycle." << endl;
                return;
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

    Graph graph(vertices, edges);

    cout << "Enter the edges and their weights (u v w):\n";
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph.addEdge(u, v, w, i);
    }

    int source;
    cout << "Enter the source vertex for the Bellman-Ford algorithm: ";
    cin >> source;

    graph.bellmanFord(source);

    return 0;
}
