/* Created by Ishaan Shah on 24-01-2019.
* Problem Name: Socks
* Problem Link: https://codeforces.com/problemset/problem/731/C
*/

#include <bits/stdc++.h>

using namespace std;

int n, m, k, cur, mx;
int clr[200005], vis[200005];
map <int, int> cnt;
vector<int> adj[200005];

void dfs(int s) {
	vis[s] = 1;
	cnt[clr[s]]++;
	mx = max(mx, cnt[clr[s]]);
	cur++;
	for (int u: adj[s]) {
		if (vis[u]) continue;
		dfs(u);		
	}
}

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	memset(vis, 0, sizeof vis);
	
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &clr[i]);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[b].push_back(a); adj[a].push_back(b);
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			cnt.clear();
			cur = 0; mx = 0;
			dfs(i);
			ans += cur-mx;
		}
	}
	
	printf("%d", ans);
}
