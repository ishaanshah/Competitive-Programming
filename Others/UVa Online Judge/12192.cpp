/* Created by Ishaan Shah on 27-07-2018.
* Problem Name: Grapevine
* Problem Link: https://uva.onlinejudge.org/external/121/12192.pdf
*/

#include <bits/stdc++.h>

using namespace std;

int n, m, q;
int grid[505][505];
int ub[10005], lb[10005];

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	
	while (scanf("%d %d", &n, &m) != EOF) {
		if (n == 0 && m == 0) break;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) 
			scanf("%d", &grid[i][j]);
		scanf("%d", &q);
		for (int i = 0; i < q; i++) scanf("%d %d", &lb[i], &ub[i]);
		
		for (int i = 0; i < q; i++) {
			int lo = lb[i], hi = ub[i];
			int ans = 0;
			for (int j = 0; j < n; j++) {
				int temp = 0;
				int lidx = lower_bound(grid[j], grid[j]+m, lo) - grid[j];
				int k = j, hidx = lidx;
				while (k < n && hidx < m) {
					if (grid[k][hidx] <= hi) {
						temp++;
					}
					k++; hidx++;
				}
				ans = max(ans, temp);
			}
			printf("%d\n", ans);
		}
		
		printf("-\n");
	}
}
