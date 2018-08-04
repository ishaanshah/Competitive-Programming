/* Created by Ishaan Shah on 03-08-2018.
* Problem Name: Cow Checklist
* Problem Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=670
*/

#include <bits/stdc++.h>

#define INF 1e9

using namespace std;

int g, h;
int gx[1005], gy[1005], hx[1005], hy[1005];
int memo[1005][1005][2], visited[1005][1005][2];

int dist(int x1, int x2, int y1, int y2) {
	return pow(x1-x2, 2) + pow(y1-y2, 2);
}

int dp(int i, int j, int curr) {
	if (i == h && j == g) {
		if (curr == 0) return 0;
		else return dist(gx[j], hx[i], gy[j], hy[i]);		
	}
	int &ans = memo[i][j][curr];
	if (visited[i][j][curr]) return ans;
	visited[i][j][curr] = 1;
	ans = INF;
	if (j+1 <= g) {
		if (curr == 0)
			ans = min(ans, dp(i, j+1, 1) + dist(hx[i], gx[j+1], hy[i], gy[j+1]));
		else 
			ans = min(ans, dp(i, j+1, 1) + dist(gx[j], gx[j+1], gy[j], gy[j+1]));
	} 
	if (i+1 <= h) { 
		if (curr == 0)
			ans = min(ans, dp(i+1, j, 0) + dist(hx[i], hx[i+1], hy[i], hy[i+1]));
		else 
			ans = min(ans, dp(i+1, j, 0) + dist(gx[j], hx[i+1], gy[j], hy[i+1]));
	}
	return ans; 
}

int main() {
	freopen("checklist.in", "r", stdin);
	freopen("checklist.out", "w", stdout);
	scanf("%d %d", &h, &g);
	for (int i = 1; i <= h; i++) scanf("%d %d", &hx[i], &hy[i]);
	for (int i = 1; i <= g; i++) scanf("%d %d", &gx[i], &gy[i]);
	memset(visited, 0, sizeof visited);
	int ans = dp(1, 0, 0);
	printf("%d", ans);
}
