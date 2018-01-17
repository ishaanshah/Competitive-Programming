/* Created by Ishaan Shah on 05-01-2018.
 * Implementation of Kruskal's Algorithm using STL
*/

#include <bits/stdc++.h>

using namespace std;

int *parent;
int *rnk;

void create(int u) {
    parent[u] = u;
    rnk[u] = 0;
}

int find(int u) {
    if(u != parent[u]) {
        parent[u] = find(parent[u]);
    }
    return parent[u];
}

void merge(int u, int v) {
    int x = find(u);
    int y = find(v);
    if(rnk[x] > rnk[y]) {
        parent[y] = x;
    } else if(rnk[y] > rnk[x]) {
        parent[x] = y;
    } else {
        parent[x] = y;
        rnk[x]++;
    }
}

int main() {
    int v, e;
    cin >> v >> e;
    pair<int, pair<int, int> >edges[e];
    set<pair<int, int> > result;
    parent = new int[v];
    rnk = new int[v];
    for(int i = 0; i < e; i++) {
        int w, a, b;
        cin >> a >> b >> w;
        edges[i].first = w;
        edges[i].second.first = a;
        edges[i].second.second = b;
    }
    for(int i = 0; i < v; i++) {
        create(i);
    }
    sort(edges, edges+e);
    int count = 0;
    for(auto edge:edges) {
        int a = edge.second.first;
        int b = edge.second.second;
        if(find(a) != find(b)) {
            merge(a, b);
            count++;
            result.insert({a, b});
        }

        if(count == v-1) {
            break;
        }
    }
    for(auto edge:result) {
        cout << edge.first << " " << edge.second << endl;
    }
}