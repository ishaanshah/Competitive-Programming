/* Created by Ishaan Shah on 28-11-2018.
* Problem Name: Little Red Riding Hood
* Problem Link: https://www.codechef.com/ZCOPRAC/problems/ZCO13002
*/

#include <bits/stdc++.h>

#define INF 1e14

using namespace std;

long long n, m;
long long wtgrd[505][10005], sfgrd[505][10005], memo[505][10005], vis[505][100005];
long long str[10005];
pair <long long, long long> mgc[10005];

long long dp (long long x, long long y) {
	long long &ans = memo[x][y];
	if (vis[x][y]) return ans;
	vis[x][y] = 1;
	if (x >= n or y >= n) return -INF;
	else if (sfgrd[x][y]) {
	    if (x == n-1 and y == n-1) ans = wtgrd[x][y];
	    else ans = max(dp(x+1, y), dp(x, y+1)) + wtgrd[x][y];
	    return ans;
	} else {
	    ans = -INF;
	    return ans;
	}
}


int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.in", "r", stdin);
		freopen("output.out", "w", stdout);
	#endif
	
	memset(sfgrd, 0, sizeof sfgrd);
	memset(vis, 0, sizeof vis);
	cin >> n >> m;
	for (long long i = 0; i < n; i++) for (long long j = 0; j < n; j++) cin >> wtgrd[i][j];
	for (long long i = 0; i < m; i++) cin >> mgc[i].first >> mgc[i].second >> str[i];

	for (long long i = 0; i < m; i++) {
		long long x = mgc[i].first-1, y = mgc[i].second-1, k = str[i];
		for (long long dx = max(0ll, x-k); dx < min(n, x+k+1); dx++) {
			for (long long dy = max(0ll, y-k); dy < min(n, y+k+1); dy++) {
				if (abs(x-dx) + abs(y-dy) <= k) sfgrd[dx][dy] = 1;
			}
		}
	}
	
	long long ans = dp(0, 0);
	if (ans == -INF) cout << "NO";
	else cout << "YES" << endl <<  ans;
}
