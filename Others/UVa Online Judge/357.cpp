/* Created by Ishaan Shah on 27-06-2018.
* Problem Name: Let Me Count The Ways
* Problem Link: https://uva.onlinejudge.org/external/3/357.pdf
*/

#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll memo[6][30005];
ll visited[6][30005];
ll n;
ll denom[5] = {1, 5, 25, 10, 50};

ll dp(ll type, ll value) {
	if (type == 5) return 0;
	if (value == 0) return 1;
	if (value < 0) return 0;
	ll &ans = memo[type][value];
	if (visited[type][value]) return ans;
	visited[type][value] = 1;
	ans = dp(type+1, value) + dp(type, value-denom[type]);	
	return ans;
}

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	while (scanf("%lld", &n) != EOF) {
		ll ans = dp(0, n);
		if (ans == 1) printf("There is only 1 way to produce %lld cents change.\n", n);
		else printf("There are %lld ways to produce %lld cents change.\n", ans, n);
	}
}
