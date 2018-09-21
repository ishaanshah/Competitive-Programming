/* Created by Ishaan Shah on 19-09-2018.
* Problem Name: Radio Contact
* Problem Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=598
*/

#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

int n, m;
int dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0};
int memo[1005][1005], vis[1005][1005];
int ins_f[1005], ins_c[1005];
pair<int, int> pos_f[1005], pos_c[1005];
int cost[1005][1005];

int dist(pair<int, int> pos_f, pair<int, int> pos_c) {
	return pow((pos_f.x-pos_c.x), 2) + pow((pos_f.y-pos_c.y), 2);
}

int dp(int i, int j) {
	if (i == n && j == m) return cost[i][j];
	int &ans = memo[i][j];
	if (vis[i][j]) return ans;
	vis[i][j] = 1;
	if (i == n) ans = dp(i, j+1);
	else if (j == m) ans = dp(i+1, j);
	else ans = min(dp(i, j+1), min(dp(i+1, j), dp(i+1, j+1)));
	ans += cost[i][j];
	return ans;
}

int main() {
	freopen("radio.in", "r", stdin);
	freopen("radio.out", "w", stdout);
	
	memset(vis, 0, sizeof vis);
	scanf("%d %d", &n, &m);
	scanf("%d %d", &pos_f[0].x, &pos_f[0].y);
	scanf("%d %d", &pos_c[0].x, &pos_c[0].y);
	string t;
	cin >> t;
	int ins;
	for (int i = 1; i <= n; i++) {
		if (t[i-1] == 'N') ins = 0;
		else if (t[i-1] == 'W') ins = 1;
		else if (t[i-1] == 'S') ins = 2;
		else if (t[i-1] == 'E') ins = 3;
		pos_f[i].x = pos_f[i-1].x+dx[ins];
		pos_f[i].y = pos_f[i-1].y+dy[ins];
	}
	cin >> t;
	for (int i = 1; i <= m; i++) {
		if (t[i-1] == 'N') ins = 0;
		else if (t[i-1] == 'W') ins = 1;
		else if (t[i-1] == 'S') ins = 2;
		else if (t[i-1] == 'E') ins = 3;
		pos_c[i].x = pos_c[i-1].x+dx[ins];
		pos_c[i].y = pos_c[i-1].y+dy[ins];
	}
	for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++)
		cost[i][j] = dist(pos_f[i], pos_c[j]);	
			
	int ans = min(dp(0, 1), min(dp(1, 0), dp(1, 1)));
	printf("%d", ans);
}
