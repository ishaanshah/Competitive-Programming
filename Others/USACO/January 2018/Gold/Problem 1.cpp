/* Created by Ishaan Shah on 28-04-2018.
* Problem Name: MooTube
* Problem Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=789
*/

#include <bits/stdc++.h>

using namespace std;

int *parent;
int *size;

int ufind(int a);
void umerge(int a, int b);

bool revsort(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b) {
    return a.first.first > b.first.first;
}

int main() {
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);

    int n, q;
    cin >> n >> q;
    pair<int, pair<int, int> > edges[n-1];
    for(int i = 0; i < n-1; i++) {
        int u, v, r;
        cin >> u >> v >> r;
        edges[i].first = r;
        edges[i].second.first = u-1;
        edges[i].second.second = v-1;
    }
    sort(edges, edges + n-1);
    parent = new int[n];
    size = new int[n];
    for(int i = 0; i < n; i++) {
        parent[i] = i;
        size[i] = 1;
    }
    pair<pair<int, int>, int> query[q];
    for(int i = 0; i < q; i++) {
        int k, v;
        cin >> k >> v;
        query[i].first.first = k;
        query[i].first.second = v-1;
        query[i].second = i;
    }
    sort(query, query+q, revsort);
    int ans[q];
    int idx = n-2;
    for(int i = 0; i < q; i++) {
        while(idx >= 0 and edges[idx].first >= query[i].first.first) {
            umerge(edges[idx].second.first, edges[idx].second.second);
            idx--;
        }
        ans[query[i].second] = size[ufind(query[i].first.second)] - 1;
    }
    for(int i = 0; i < q; i++) {
        cout << ans[i] << endl;
    }
}

int ufind(int a) {
    return parent[a] == a ? a : (parent[a] = ufind(parent[a]));
}

void umerge(int a, int b) {
    int pa = ufind(a);
    int pb = ufind(b);
    size[pa] += size[pb];
    parent[pb] = pa;
}