/* Created by Ishaan Shah on 24-01-2019.
* Problem Name: Mahmoud and Ehab and the message
* Problem Link: https://codeforces.com/problemset/problem/959/B
*/

#include <bits/stdc++.h>

#define INF 1e15

using namespace std;

long long n, k, m;
long long cost[100005];
map <string, long long> mp;
string msg[100005];

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	
	// Take input
	scanf("%lld %lld %lld", &n, &k, &m);
	string s;
	long long t;
	for (long long i = 0; i < n; i++) {
		cin >> s;
		mp[s] = i; 
	}
	for (long long i = 0; i < n; i++) scanf("%lld", &cost[i]);
	for (long long i = 0; i < k; i++) {
		scanf("%lld", &t);
		long long arr[t], mn = INF;
		for (long long j = 0; j < t; j++) scanf("%lld", &arr[j]);
		for (long long j = 0; j < t; j++) mn = min(mn, cost[arr[j]-1]);
		for (long long j = 0; j < t; j++) cost[arr[j]-1] = mn;
	}
	for (long long i = 0; i < m; i++) cin >> msg[i];
	
	long long ans = 0;
	for (long long i = 0; i < m; i++) {
		long long idx = mp[msg[i]];
		ans += cost[idx];
	}
	
	printf("%lld", ans);
}
