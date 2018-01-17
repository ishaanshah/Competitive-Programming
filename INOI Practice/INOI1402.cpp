/* Created by Ishaan Shah on 12-12-2017.
 * Problem Name: INOI1402
 * Problem Link: https://www.codechef.com/INOIPRAC/problems/INOI1402
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
    int dijkstra(int start);
};

Graph::Graph(int v) {
    this->v = v;
    adj = new list<pair<int, int> > [v];
}

void Graph::add_edge(int u, int v, int w) {
    adj[u].emplace_back(make_pair(v, w));
    adj[v].emplace_back(make_pair(u, w));
}

int Graph::dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    vector<int> dist(v, inf);

    q.push(make_pair(0, start));
    dist[start] = 0;


    while(!q.empty()) {
        int u = q.top().second;
        q.pop();

        for(auto vertex: adj[u]) {
            if(dist[vertex.first] > dist[u] + vertex.second) {
                dist[vertex.first] = dist[u] + vertex.second;
                q.push(make_pair(dist[vertex.first], vertex.first));
            }
        }
    }

    return dist[max_element(dist.begin(), dist.end()) - dist.begin()];
}

int main() {
    int c, f, u, v, w;
    cin >> c >> f;
    Graph flights(c);
    for(int i = 0; i < f; i++) {
        cin >> u >> v >> w;
        flights.add_edge(u-1, v-1, w);
    }
    int ans = 0;
    for(int i = 0; i < c; i++)
    {
        ans = max(ans, flights.dijkstra(i));
    }
    cout << ans;
}