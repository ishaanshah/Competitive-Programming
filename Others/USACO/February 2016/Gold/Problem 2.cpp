/* Created by Ishaan Shah on 16-10-2018.
* Problem Name: Circular Barn Revisited
* Problem Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=622
*/

#include <bits/stdc++.h>

#define INF 1e13

using namespace std;

typedef long long ll;

ll N, K, str, num[105];
ll memo[105][105][8], vis[105][105][8];

ll dp(ll i, ll lo, ll k) {
	if ((i+1)%N == str && k > 1) return INF;
	if ((i+1)%N == str && k == 1) return 0;
	if ((i+1)%N == str && k == 0) return lo*num[i];
	ll &ans = memo[i][lo][k];
	if (vis[i][lo][k]) return ans;
	vis[i][lo][k] = 1;
	if (k > 0) {
		ans = min(dp((i+1)%N, 1, k-1), dp((i+1)%N, lo+1, k)+num[i]*lo);
	} else {
		ans = dp((i+1)%N, lo+1, k)+num[i]*lo;
	}
	return ans;
}

int main() {
	freopen("cbarn2.in", "r", stdin);
	freopen("cbarn2.out", "w", stdout);
	
	scanf("%lld %lld", &N, &K);
	for (ll i = 0; i < N; i += 1) scanf("%lld", &num[i]);
	ll ans = INF;
	for (ll i = 0; i < N; i += 1) {
		memset(vis, 0, sizeof vis);
		str = i;
		ans = min(ans, dp((i+1)%N, 1, K-1));
	}
	printf("%lld", ans);
}
