/* Created by Ishaan Shah on 22-01-2019.
* Problem Name: Star Sky
* Problem Link: https://codeforces.com/problemset/problem/835/C
*/

#include <bits/stdc++.h>

using namespace std;

int n, q, c;
int grd[105][105][15];

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	
	memset(grd, 0, sizeof grd);
	scanf("%d %d %d", &n, &q, &c);
	for (int i = 0; i < n; i++) {
		int x, y, s;
		scanf("%d %d %d", &x, &y, &s); 
		grd[x][y][s]++;
	}
	
	for (int k = 0; k <= c; k++) {
		for (int i = 1; i < 101; i++) {
			for (int j = 1; j < 101; j++) {
				grd[i][j][k] += grd[i-1][j][k]+grd[i][j-1][k]-grd[i-1][j-1][k];
			}
		}
	}
	
	while (q--) {
		int x1, x2, y1, y2, t;
		scanf("%d %d %d %d %d", &t, &x1, &y1, &x2, &y2);
		int ans = 0;
		for (int p = 0; p <= c; p++) {
			int brt = (t+p)%(c+1);
			int amt = grd[x2][y2][p]-grd[x1-1][y2][p]-grd[x2][y1-1][p]+grd[x1-1][y1-1][p];
			ans += brt*amt; 
		}
		printf("%d\n", ans);
	}
}
