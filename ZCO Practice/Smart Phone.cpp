/* Created by Ishaan Shah on 05-11-2018.
* Problem Name: Smart Phone
* Problem Link: https://www.codechef.com/ZCOPRAC/problems/ZCO14003
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;
ll arr[1000005];

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.in", "r", stdin);
		freopen("output.out", "w", stdout);
	#endif
	
	scanf("%lld", &n);
	for (int i = 0; i < n; i += 1) scanf("%lld", &arr[i]);
	sort(arr, arr+n);
	ll ans = 0;
	for (int i = 0; i < n; i+= 1) {
		ans = max(ans, arr[i]*(n-i));
	}
	printf("%lld", ans);
}
