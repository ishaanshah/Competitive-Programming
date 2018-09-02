/* Created by Ishaan Shah on 02-09-2018.
* Problem Name: Bessie's Dream
* Problem Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=575
*/

#include <bits/stdc++.h>

#define INF 1e7

using namespace std;

typedef pair<int, int> pi;
typedef pair<pi, int> pii;

int m, n;
int grid[1005][1005], dist[1005][1005], visited[1005][1005];
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

bool check(int x, int y) {
	return (0 <= x && x < n) && (0 <= y && y < m);
}

int bfs() {
	dist[0][0] = 0;
	queue<pii> q;
	q.push({{0, 0}, 0});
	while (!q.empty()) {
		pii u = q.front(); q.pop();
		int x = u.first.first, y = u.first.second, o = u.second;
		if (visited[x][y]) continue;
		int vx = 0, vy = 0;
		for (int i = 0; i < 4; i++) {
			vx = x+dx[i]; vy = y+dy[i];
			if (check(vx, vy)) {
				int ux = x, uy = y;
				int t = grid[vx][vy];
				if (t == 4) {
					o &= 0;
					dist[vx][vy] = dist[x][y]+1;
					while (true) {
						vx = ux+dx[i], vy  = uy+dy[i];
						if (!check(vx, vy)) break;
						t = grid[vx][vy];
						if (t != 4) break;
						if (grid[vx][vy] == 0) break;
						dist[vx][vy] = dist[ux][uy]+1;
						ux = vx; uy = vy;
					}					
				}
				
				if (t == 0) continue;
				else if (t == 1) {
					q.push({{vx, vy}, o});
					dist[vx][vy] = min(dist[vx][vy], dist[ux][uy]+1);
				} else if (t == 2) {
					o |= 1;
					q.push({{vx, vy}, o});
					dist[vx][vy] = min(dist[vx][vy], dist[ux][uy]+1);
				} else if (t == 3 && o == 1) {
					q.push({{vx, vy}, o});
					dist[vx][vy] = min(dist[vx][vy], dist[ux][uy]+1);
				} else if (t == 3 && o == 0) continue;
			}	
		}
		visited[x][y] = 1;
	}
	return dist[n-1][m-1];
}

int main() {
	freopen("dream.in", "r", stdin);
	freopen("dream.out", "w", stdout);
	
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &grid[i][j]);
			visited[i][j] = 0;
			dist[i][j] = INF;
		}
	}
	int ans = bfs();
	if (ans == INF) printf("-1");
	else printf("%d", ans);
} 
