/* Created by Ishaan Shah on 30-12-2017.
 * Implementation of Topological Sort using STL
*/

#include <bits/stdc++.h>

using namespace std;

class Graph {
    int v;
    int *indegree;
    int *outdegree;
    list<int> *in;
    list<int> *out;

public:
    explicit Graph(int v);
    ~Graph();
    void add_edge(int u, int v);
    list<int> topo_sort();
};

Graph::Graph(int v) {
    this->v = v;
    indegree = new int[v];
    outdegree = new int[v];
    for(int i = 0; i < v; i++) {
        indegree[i] = 0;
        outdegree[i] = 0;
    }
    in = new list<int>[v];
    out = new list<int>[v];
}

Graph::~Graph() {
    delete [] in;
    delete [] indegree;
    delete [] out;
    delete [] outdegree;
}

void Graph::add_edge(int u, int v) {
    in[v].push_back(u);
    indegree[v]++;
    out[u].push_back(v);
    outdegree[u]++;
}

list<int> Graph::topo_sort() {
    list<int> result;
    queue<int> q;
    for(int i = 0; i < v; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);
        for (auto vertex: out[u]) {
            indegree[vertex]--;
            if (indegree[vertex] == 0) {
                q.push(vertex);
            }
        }
    }
    return result;
}

int main() {
    int v, n;
    cin >> v >> n;
    Graph graph(v);

    while(n--) {
        int x, y;
        cin >> x >> y;
        graph.add_edge(x-1, y-1);
    }

    list<int> result = graph.topo_sort();
    for(int vertex: result) {
        cout << vertex + 1 << " ";
    }
}