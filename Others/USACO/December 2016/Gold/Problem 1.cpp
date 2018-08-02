/* Created by Ishaan Shah on 02-08-2018.
* Problem Name: Moocast
* Problem Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=669
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, cnt;
int x[1005], y[1005];
vector<int> adj[1005];
bool visited[1005];

ll dist(int i, int j) {
	return pow(x[i]-x[j], 2) + pow(y[i]-y[j], 2);
}

void dfs(ll start) {
	if (visited[start]) {
		return;
	}
	visited[start] = true;
	cnt++;
	for (int i = 0; i < adj[start].size(); i++) {
		dfs(adj[start][i]);
	}
}

bool check(ll mid) {
	cnt = 0;
	memset(visited, false, sizeof visited);
	for (int i = 0; i < n; i++) {
		adj[i].clear();
	}
	for (int i = 0; i < n; i++) for (int j = i+1; j < n; j++) {
		if (dist(i, j) <= mid) {
			adj[i].push_back(j);
			adj[j].push_back(i);
		}
	}
	dfs(0);
	if (cnt == n) return true;
	else return false;
}

int main() {
	freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x[i], &y[i]); 
	}
	
	ll hi = 1250000005, lo = 1, mid, ans;
	while (lo <= hi) {
		mid = (lo+hi)/2;
		if (check(mid)) {
			ans = mid;
			hi = mid-1;
		} else lo = mid+1;
	}
	printf("%lld", ans);
}
