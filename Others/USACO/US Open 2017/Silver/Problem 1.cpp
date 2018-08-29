/* Created by Ishaan Shah on 29-08-2018.
* Problem Name: Paired Up
* Problem Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=738
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;

ll n;
pi a[100005];

int main() {
	freopen("pairup.in", "r", stdin);
	freopen("pairup.out", "w", stdout);
	
	scanf("%lld", &n);
	for (int i = 0; i < n; i += 1) scanf("%lld %lld", &a[i].second, &a[i].first);
	sort(a, a+n);
	
	ll f = 0, l = n-1;
	ll ans = 0, temp = 0;
	while (f <= l) {
		temp = min(a[f].second, a[l].second);
		if (f == l) temp /= 2;
		ans = max(ans, a[f].first+a[l].first);
		a[f].second -= temp;
		a[l].second -= temp;
		if (a[f].second == 0) f++;
		if (a[l].second == 0) l--;
		
	}	
	printf("%lld", ans);
}
