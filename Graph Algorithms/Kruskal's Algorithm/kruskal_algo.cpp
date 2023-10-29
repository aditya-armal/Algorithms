#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int source, destination, weight;

    // Custom comparator for sorting edges
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class Graph {
private:
    int V; // Number of vertices
    vector<Edge> edges;

public:
    Graph(int vertices) {
        V = vertices;
    }

    void addEdge(int u, int v, int w) {
        edges.push_back({u, v, w});
    }

    int find(vector<int>& parent, int vertex) {
        if (parent[vertex] == -1)
            return vertex;
        return find(parent, parent[vertex]);
    }

    void unionSet(vector<int>& parent, int x, int y) {
        int rootX = find(parent, x);
        int rootY = find(parent, y);
        parent[rootX] = rootY;
    }

    void kruskalMST() {
        vector<int> parent(V, -1);
        vector<Edge> result;
        int totalWeight = 0;

        sort(edges.begin(), edges.end());

        for (Edge edge : edges) {
            int rootSrc = find(parent, edge.source);
            int rootDest = find(parent, edge.destination);

            if (rootSrc != rootDest) {
                result.push_back(edge);
                totalWeight += edge.weight;
                unionSet(parent, rootSrc, rootDest);
            }
        }

        cout << "Edges in the Minimum Spanning Tree:\n";
        for (Edge edge : result) {
            cout << edge.source << " - " << edge.destination << " (" << edge.weight << ")\n";
        }

        cout << "Total Weight of the Minimum Spanning Tree: " << totalWeight << endl;
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

    graph.kruskalMST();

    return 0;
}
