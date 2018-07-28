/* Created by Ishaan Shah on 28-07-2018.
* Problem Name: Fill the Containers
* Problem Link: https://uva.onlinejudge.org/external/114/11413.pdf
*/

#include <bits/stdc++.h>

#define MAXC 10e9 + 5

using namespace std;

typedef long long ll;

ll n, m;
ll cap[1000005];

bool check(ll mcap) {
	ll sum = 0, req = 0;
	for (int i = 0; i < n; i++) {
		if (cap[i] > mcap) return false;
		if (sum + cap[i] > mcap) sum = 0;
		if (sum == 0) req++;
		if (req > m) return false;
		sum += cap[i];
	}
	return true;
}

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	
	while (scanf("%lld %lld", &n, &m) != EOF) {
		ll hi = 0;
		for (int i = 0; i < n; i += 1) {
			scanf("%lld", &cap[i]);
			hi += cap[i];
		}
		ll lo = 1, ans = 0;
		while (lo <= hi) {
			ll mid = (lo+hi)/2;
			if (check(mid)) {
				ans = mid;
				hi = mid-1;
			} else lo = mid+1;
		}
		
		printf("%lld\n", ans);
	}
}
