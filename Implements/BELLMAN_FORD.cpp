/* Created by Ishaan Shah on 13-12-2017.
 Implementation of Bellman-Ford algorithm using STL
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
    map<int, pair<int, int> > bellman_ford(int start);
};

Graph::Graph(int v) {
    this->v = v;
    adj = new list<pair<int, int> > [v];
}

void Graph::add_edge(int u, int v, int w) {
    adj[u].emplace_back(make_pair(v, w));
    adj[v].emplace_back(make_pair(u, w));
}

map<int, pair<int, int> > Graph::bellman_ford(int start) {
    vector<int> dist(v, inf);
    vector<int> parent(v, -1);
    map<int, pair<int, int> > result;
    dist[start] = 0;
    for(int i = 0; i < v-1; i++) {
        // This loops runs over all edges of graph. It's time complexity is O(|E|).
        for(int j = 0; j < v; j++) {
            for(auto &elem: adj[j]) {
                if(dist[elem.first] > dist[j] + elem.second) {
                    dist[elem.first] = dist[j] + elem.second;
                    parent[elem.first] = j;
                }
            }
        }
    }
    // check for negative weight cycles. It returns an empty map result to denote that a shortest path is not well defined
    for(int j = 0; j < v; j++) {
        for(auto &elem: adj[j]) {
            if(dist[elem.first] > dist[j] + elem.second) {
                return result;
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
    ans = graph.bellman_ford(0);
    for(auto &elem: ans) {
        cout << elem.first << " " << elem.second.first << " " << elem.second.second << endl;
    }
}