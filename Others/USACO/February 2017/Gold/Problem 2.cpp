/* Created by Ishaan Shah on 20-08-2018.
* Problem Name: Why Did the Cow Cross the Road II(Gold)
* Problem Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=718
*/

#include <bits/stdc++.h>

using namespace std;

int n;
int memo[1005][1005], vis[1005][1005];
int a[1005], b[1005];

int dp(int i, int j) {
	if (i == n || j == n) return 0;
	int &ans = memo[i][j];
	if (vis[i][j]) return ans;
	vis[i][j] = 1;
	if (abs(a[i]-b[j]) <= 4) ans = dp(i+1, j+1)+1;
	ans = max(ans, dp(i+1, j)); ans = max(ans, dp(i, j+1));
	return ans;
}

int main() {
	freopen("nocross.in", "r", stdin);
	freopen("nocross.out", "w", stdout);
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) scanf("%d", &b[i]);
	memset(vis, 0, sizeof vis);
	int ans = dp(0, 0);
	printf("%d", ans);
}
