/* Created by Ishaan Shah on 24-01-2019.
* Problem Name: Love Rescue
* Problem Link: https://codeforces.com/problemset/problem/939/D
*/

#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> adj[26];
int vis[26];
vector<pair<int, int> > ans;
string s1, s2;

void dfs(int s) {
	if (vis[s]) return;
	vis[s] = 1;
	for (int u: adj[s]) {
		if (vis[u]) continue;
		else {
			ans.push_back({u, s});
			dfs(u);
		}
	}
}

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	memset(vis, 0, sizeof vis);

	scanf("%d", &n);
	cin >> s1 >> s2;
	for (int i = 0; i < n; i++) {
		int a = s1[i]-'a';
		int b = s2[i]-'a';
		adj[a].push_back(b); adj[b].push_back(a);
	}
	for (int i = 0; i < 26; i++) dfs(i);
	
	printf("%d\n", (int)ans.size());
	for (int i = 0; i < (int)ans.size(); i++) {
		printf("%c %c\n",'a'+ans[i].first, 'a'+ans[i].second);
	}
}
