/* Created by Ishaan Shah on 30-06-2018.
* Problem Name: Flight Planner
* Problem Link: https://uva.onlinejudge.org/external/103/10337.pdf
*/

#include <bits/stdc++.h>

#define INF 10e7

using namespace std;

int n;
int grid[1005][15], memo[1005][15], visited[1005][15];

int dp(int x, int y) {
	if ((x == n && y != 0) || y > 9 || y < 0) return INF;
	if (x == n && y == 0) return 0;
	int &ans = memo[x][y];
	if (visited[x][y]) return ans;
	visited[x][y] = 1;
	ans = INF;
	ans = min(dp(x+1, y-1) + 20, dp(x+1, y) + 30);
	ans = min(ans, dp(x+1, y+1) + 60) - grid[x][y];
	return ans;
}

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		n /= 100;
		memset(visited, 0, sizeof visited);
		for (int j = 9; j >= 0; j -= 1) for (int i = 0; i < n; i += 1){
			scanf("%d", &grid[i][j]);
		}
		printf("%d\n\n", dp(0, 0));
	}
}
