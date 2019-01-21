/* Created by Ishaan Shah on 14-01-2019.
* Problem Name: Mooyo Mooyo
* Problem Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=860
*/

#include <bits/stdc++.h>

using namespace std;

int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
int n, l, cnt;
int grid[10][105];
bool vis[10][105];
string s;
vector<pair<int, int> > reg;

void rotate(int c, int r) {
	int temp = grid[c][r];
	for (int i = r; i > 0; i--) {
		grid[c][i] = grid[c][i-1];
	}
	grid[c][0] = temp;
}

void pprint() {
	for (int j = 0; j < n; j++) {
		for (int i = 0; i < 10; i++)
			printf("%d ", grid[i][j]);
        printf("\n");
	}
}

void dfs(int x, int y, int clr) {
	if (vis[x][y]) return;
	vis[x][y] = true;
	reg.push_back(make_pair(x, y));
	for (int i = 0; i < 4; i++) {
		int nx = x+dx[i], ny = y+dy[i];
		if (nx < 0 or nx >= 10) continue;
		if (ny < 0 or ny >= n) continue;
		if (grid[nx][ny] == clr) {
			dfs(nx, ny, clr);
		}
	}
}

int main() {
	freopen("mooyomooyo.in", "r", stdin);
	freopen("mooyomooyo.out", "w", stdout);
	
	// Input
	scanf("%d %d", &n, &l);
	for (int i = 0; i < n; i++) {
		cin >> s;
    	for (int j = 0; j < 10; j++) grid[j][i] = s[j]-'0';
	}
	
	while (true) {
		// Reset
		memset(vis, false, sizeof vis);
		cnt = 0;
		
		// Delete cells		
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 0) continue;
				if (vis[i][j]) continue;
				dfs(i, j, grid[i][j]);
				if (reg.size() >= l) {
					for (auto& v: reg) grid[v.first][v.second] = 0;
					cnt++;	
				}
				reg.clear();
			}
		}
		
		// Gravity
		for (int i = 0; i < 10; i++) {
			for (int j = n-1; j >= 0; j--) {
				int k = j+1;
				while (grid[i][j] == 0 && k > 0) {
					rotate(i, j);
					k--;
				}
			}
		}
		
		// Break if complete
		if (cnt == 0) break;
	}
	
	// Output
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%d", grid[j][i]);
		}
		printf("\n");
	}
}
