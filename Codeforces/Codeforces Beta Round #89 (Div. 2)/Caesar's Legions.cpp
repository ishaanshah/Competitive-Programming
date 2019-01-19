/* Created by Ishaan Shah on 19-01-2019.
* Problem Name: Caesar's Legions
* Problem Link: https://codeforces.com/contest/118/problem/D
*/

#include <bits/stdc++.h>
#define mod 100000000

using namespace std;

int N1, N2, K1, K2;
int memo[105][105][15][15], vis[105][105][15][15];

int dp(int n1, int n2, int k1, int k2) {
	if (n1 == 0 && n2 == 1 && k2 > 0) return 1;
	else if (n1 == 1 && n2 == 0 && k1 > 0) return 1; 
	else if (n1 == 0 && k2 == 0) return 0;
	else if (n2 == 0 && k1 == 0) return 0;
	int &ans = memo[n1][n2][k1][k2];
	if (vis[n1][n2][k1][k2]) return ans;
	vis[n1][n2][k1][k2] = 1;
	if (n1 > 0 && n2 > 0 && k1 > 0 && k2 > 0)
		ans = ((dp(n1-1, n2, k1-1, K2) % mod) + (dp(n1, n2-1, K1, k2-1) % mod)) % mod;
	else if (n1 == 0 && k2 > 0) ans = dp(0, n2-1, K1, k2-1) % mod;
	else if (n2 == 0 && k1 > 0) ans = dp(n1-1, 0, k1-1, K2) % mod;
	else if (n1 > 0 && n2 > 0 && k1 == 0) ans = dp(n1, n2-1, K1, k2-1) % mod;
	else if (n1 > 0 && n2 > 0 && k2 == 0) ans = dp(n1-1, n2, k1-1, K2) % mod;
	return ans;
}

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	
	memset(vis, 0, sizeof vis);
	scanf("%d %d %d %d", &N1, &N2, &K1, &K2);
	int ans = dp(N1, N2, K1, K2);
	printf("%d", ans);	
}
