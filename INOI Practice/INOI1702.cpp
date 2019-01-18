/* Created by Ishaan Shah on 18-01-2019.
* Problem Name: Training
* Problem Link: https://www.codechef.com/INOIPRAC/problems/TINOI17B
*/

#include <bits/stdc++.h>

using namespace std;

long long n, s;
long long str[5005], e[5005];
long long memo[5005][5005], vis[5005][5005];

long long dp(long long i, long long si) {
	if (i == n-1) return e[i]*str[si];
	long long &ans = memo[i][si];
	if (vis[i][si]) return memo[i][si];
	vis[i][si] = 1;
	ans = max(dp(i+1, si+1), dp(i+1, si)+str[si]*e[i]);
	return ans;	
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.in", "r", stdin);
		freopen("output.out", "w", stdout);
	#endif
	memset(vis, 0, sizeof vis);
	
	scanf("%lld %lld", &n, &s);
	for (long long i = 0; i < n; i++) scanf("%lld", &e[i]);
	
	// Create strength array
	str[0] = s;	
	for (long long i = 1; i < n; i++) {
		long long sum = 0, temp = str[i-1];
		while (temp) {
			sum += temp%10;
			temp = temp/10;
		}
		str[i] = str[i-1] + sum*sum*sum;
	}
	
	printf("%lld", dp(0, 0));
}
