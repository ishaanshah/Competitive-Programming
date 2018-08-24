/* Created by Ishaan Shah on 23-08-2018.
* Problem Name: Why Did the Cow Cross the Road III(Silver)
* Problem Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=716
*/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int n, k, r, cnt = 0;
int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
int vis[105][105];
vector<pi> road[105][105];
vector<pi> g[105][105];
pi cow[10005];
int cp[105][105];

void dfs(pi start) {
	int ux = start.first, uy = start.second;
	if(vis[ux][uy]) return;
	vis[ux][uy] = 1;
	if (cp[ux][uy]) cnt++;
	for (pi v: g[ux][uy]) {
		dfs(v);
	}
}

int main() {
	freopen("countcross.in", "r", stdin);
	freopen("countcross.out", "w", stdout);

	scanf("%d %d %d", &n, &k, &r);
	// Take input
	for (int i = 0; i < r; i += 1) {
		int x, y, u, v;
		scanf("%d %d %d %d", &x, &y, &u, &v);
		road[x-1][y-1].push_back({u-1, v-1});
		road[u-1][v-1].push_back({x-1, y-1});
	}
	for (int i = 0; i < k; i += 1) {
		scanf("%d %d", &cow[i].first, &cow[i].second);
		cow[i].first--; cow[i].second--;
		cp[cow[i].first][cow[i].second]++;
	}
	
	// Create the graph
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int vx = 0, vy = 0;
			for (int l = 0; l < 4; l++) {
				vx = i+dx[l]; vy = j+dy[l];
				if ((0 <= vx && vx < n) && (0 <= vy && vy < n)) {
					g[i][j].push_back({vx, vy});
					for (pi u: road[i][j]) {
						if (u.first == vx && u.second == vy) {
							g[i][j].pop_back();
							break;
						}
					}
				}
			}
		}
	}
		
	// Perform dfs on each cow
	int ans = 0;
	for (int i = 0; i < k; i++) {
		memset(vis, 0, sizeof vis);
		cnt = 0;
		dfs(cow[i]);
		ans += (k-cnt);
	}
	printf("%d", ans/2);
}
