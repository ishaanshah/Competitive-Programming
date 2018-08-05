/* Created by Ishaan Shah on 05-08-2018.
* Problem Name: Circular Intervals
* Problem Link: https://www.codechef.com/IOITC181/problems/CIRCINTE
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll m, n;
ll s[1000000], e[1000000];

bool check(ll d) {
	ll curr = s[0], first = s[0];
	for (int i = 1; i < n; i++) {
		if (curr+d < s[i]) 
			curr = s[i];
		else if (curr+d >= s[i] && curr+d <= e[i])
			curr = curr+d;
		else
			return false;
			
	}
	if (curr+d < m) return true;
	
	ll n_curr = (curr+d) % m;
	if (n_curr > e[0]) return false;
	for (int i = 1; i < n; i++) {
		if (n_curr+d < s[i]) 
			n_curr = s[i];
		else if (n_curr+d >= s[i] && n_curr+d <= e[i])
			n_curr = n_curr+d;
		else
			return false;
	}
	if (n_curr <= curr) return true;
	return false;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.in", "r", stdin);
		freopen("output.out", "w", stdout);
	#endif
	scanf("%lld %lld", &m, &n);
	
	for (int i = 0; i < n; i++) scanf("%lld %lld", &s[i], &e[i]);
	ll hi = 1e18, lo = 1, mid, ans;
	while (lo <= hi) {
		mid = (lo+hi)/2;
		if (check(mid)) {
			ans = mid;
			lo = mid+1;
		} else hi = mid-1;
	}
	printf("%lld", ans);
}
