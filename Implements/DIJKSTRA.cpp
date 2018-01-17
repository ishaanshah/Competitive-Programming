/* Created by Ishaan Shah on 13-12-2017.
 * Implementation of Dijkstra's Algorithm using STL
*/


#include <bits/stdc++.h>

using namespace std;

#define inf 0x3f3f3f3f

class Graph {
    int v;
    list<pair<int, int> > *adj;

public:
    explicit Graph(int v);
    void add_edge(int u, int v, int w);
    map<int, pair<int, int> > dijkstra(int start);
};

Graph::Graph(int v) {
    this->v = v;
    adj = new list<pair<int, int> > [v];
}

void Graph::add_edge(int u, int v, int w) {
    adj[u].emplace_back(make_pair(v, w));
    adj[v].emplace_back(make_pair(u, w));
}

map<int, pair<int, int> > Graph::dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    vector<int> dist(v, inf);
    vector<int> parent(v, -1);
    map<int, pair<int, int> > result;

    q.push(make_pair(0, start));
    dist[start] = 0;

    while(!q.empty()) {
        int u = q.top().second;
        q.pop();

        for(auto vertex: adj[u]) {
            if(dist[vertex.first] > dist[u] + vertex.second) {
                dist[vertex.first] = dist[u] + vertex.second;
                parent[vertex.first] = u;
                q.push(make_pair(dist[vertex.first], vertex.first));
            }
        }
    }
    for(int i = 0; i < v;  i++) {
        result.insert(make_pair(i, make_pair(parent[i], dist[i])));
    }
    return result;
}

int main() {
    int c, f, u, v, w;
    map<int, pair<int, int> > ans;
    cin >> c >> f;
    Graph graph(c);
    for(int i = 0; i < f; i++) {
        cin >> u >> v >> w;
        graph.add_edge(u-1, v-1, w);
    }
    ans = graph.dijkstra(0);
    for(auto &elem: ans) {
        cout << elem.first << " " << elem.second.first << " " << elem.second.second << endl;
    }
}