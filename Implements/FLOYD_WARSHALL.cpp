/* Created by Ishaan Shah on 29-12-2017.
 Implementation of Floyd-Warshall Algorithm
*/

#include <bits/stdc++.h>

using namespace std;

class Graph {
    int v;
    list<int> *adj;

public:
    explicit Graph(int v);
    void add_edge(int u, int v, int w);
    void floyd_warshall(int &parent[v][v], int &distance[v][v]);
};

Graph::Graph(int v) {
    this->v = v;
    adj = new list<int>[v];
}

void Graph::add_edge(int u, int v, int w) {
    adj[u].emplace_back({u, w});
    adj[v].emplace_back({v, w});
}

void Graph::floyd_warshall(int &parent[v][v], int &distance[v][v]) {
    for(int i = 0; i < v; i++) {
        for(int j = 0; j < v; j++) {
            for(int k = 0; k < v; k++) {
                if (distance[i][k] + distance[k][j] < distance[i][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }
}

int main() {
    int n, vertex;
    cin >> vertex >> n;
    Graph graph(vertex);
    for(int i = 0; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph.add_edge(u, v, w);
    }

}
