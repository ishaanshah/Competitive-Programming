/* Created by Ishaan Shah on 25-01-2019.
* Problem Name: D. Fight Against Traffic
* Problem Link: https://codeforces.com/problemset/problem/954/D
*/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int n, m, s, t;
int vis[1005], dist1[1005], dist2[1005];
queue <pi> q;
set <int> st[1005];
vector <int> adj[1005];

int main() {
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	
	scanf("%d %d %d %d", &n, &m, &s, &t);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v); adj[v].push_back(u);
		st[u].insert(v); st[v].insert(u);
	}
	
	memset(vis, 0, sizeof vis);
	q.push({s, 0});
	vis[s] = 1;
	dist1[s] = 0;
	while (!q.empty()) {
		pi u = q.front(); q.pop();
		for (int v: adj[u.first]) {
			if (vis[v]) continue;
			q.push({v, u.second+1});
			dist1[v] = u.second+1;
			vis[v] = 1;
		}
	}
	
	memset(vis, 0, sizeof vis);
	q.push({t, 0});
	vis[t] = 1;
	dist2[t] = 0;
	while (!q.empty()) {
		pi u = q.front(); q.pop();
		for (int v: adj[u.first]) {
			if (vis[v]) continue;
			q.push({v, u.second+1});
			dist2[v] = u.second+1;
			vis[v] = 1;
		}
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i+1; j <= n; j++) {
			if (dist1[t] <= 1+dist1[i]+dist2[j] and dist1[t] <= 1+dist1[j]+dist2[i] and st[i].find(j) == st[i].end() and st[j].find(i) == st[j].end()) ans++;
		}
	}
	
	printf("%d", ans);
}
