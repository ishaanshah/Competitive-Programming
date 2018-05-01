/* Created by Ishaan Shah on 30-04-2018.
* Problem Name: Cow At Large
* Problem Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=790
*/

#include <bits/stdc++.h>

using namespace std;

bool *res;
list<int> *adj;
int dist = 0;
int level = 0;
int start;
int ans = 0;
vector<int> stk;
bool *visited;

void dfs(int s, int p) {
    if(visited[s]) return;

    stk.push_back(s);
    if(adj[s].size() == 1) {
        level = (stk.size()-1)/2;
        res[*(stk.end()-level-1)] = true;
    }
    for(int child: adj[s]) {
        if(child != p) {
            dfs(child, s);
        }
    }
    stk.pop_back();
    visited[s] = true;
}

void dfs2(int s, int p) {
    if(res[s]) {
        ans++;
        return;
    }
    for(int child: adj[s]) {
        if(child != p)
            dfs2(child, s);
    }
}

int main() {
    freopen("atlarge.in", "r", stdin);
    freopen("atlarge.out", "w", stdout);

    int n;
    cin >> n >> start;
    start--;
    res = new bool[n];
    adj = new list<int>[n];
    visited = new bool[n];
    for(int i = 0; i < n; i++) {
        res[i] = false;
        visited[i] = false;
    }
    for(int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
       adj[a].push_back(b);
       adj[b].push_back(a);
    }    
    dfs(start, -1);
    dfs2(start, -1);
    cout << ans;
}