/* Created by Ishaan Shah on 26-05-2018.
* Problem Name: Directory Traversal
* Problem Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=814
*/

#include <bits/stdc++.h>

using namespace std;

vector<list<int> > graph;
vector<long long> dp1;
vector<long long> dp2;
vector<int> ln;
vector<int> bfs_order;
vector<int> size;
queue<int> q;

void bfs(int size, int start) {
    bool visited[size];
    for(int i = 0; i < size; i++) {
        visited[i] = false;
    }
    q.push(start);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v: graph[u]) {
            if(!visited[v]) {
                q.push(v);
            }
        }
        visited[u] = true;
        bfs_order.push_back(u);
    }
}

int count_ln(int start) {
    ln[start] = 0;
    if(graph[start].size() == 0) {
        return 1;
    }
    for(int u: graph[start]) {
        ln[start] += count_ln(u);
    }
    return ln[start];
}

int main() {
    freopen("dirtraverse.in", "r", stdin);
    freopen("dirtraverse.out", "w", stdout);
    
    int n;
    cin >> n;
    int par[n];
    for(int i = 0; i < n; i++) {
        par[i] = -1;
    }
    ln.resize(n);
    size.resize(n);
    graph.resize(n);
    dp1.resize(n);
    dp2.resize(n);
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        size[i] = s.length();
        int a, k;
        cin >> k;
        if(k > 0) {
            size[i]++;
        }
        for(int j = 0; j < k; j++) {
            cin >> a;
            par[--a] = i;
            graph[i].push_back(a);
        }
    }
    
    bfs(n, 0);
    count_ln(0);

    reverse(bfs_order.begin(), bfs_order.end());
    for(int u: bfs_order) {
        dp1[u] = 0;
        for(int v: graph[u]) {
            dp1[u] += dp1[v] + max(size[v], size[v]*ln[v]);
        }
    }

    reverse(bfs_order.begin(), bfs_order.end());
    for(int u: bfs_order) {
        if(u == 0 or graph[u].size() == 0) {
            dp2[u] = 0;
            continue;
        }
        dp2[u] = (ln[0] - ln[u])*3 + dp1[par[u]] - dp1[u] - ln[u]*size[u] + dp2[par[u]];
    }

    long long ans = dp1[0];
    for(int i = 1; i < n; i++) {
        if(graph[i].size() == 0) {
            continue;
        }
        ans = min(ans, dp1[i]+dp2[i]);
    }
    cout << ans;
}   