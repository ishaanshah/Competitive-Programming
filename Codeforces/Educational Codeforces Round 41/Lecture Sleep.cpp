/* Created by Ishaan Shah on 22-01-2019.
* Problem Name: Lecture Sleep
* Problem Link: https://codeforces.com/problemset/problem/961/B
*/

#include <bits/stdc++.h>

using namespace std;

int n, k, dp1[100005], dp2[100005], slp[100005], a[100005];

int main() {
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) scanf("%d", &slp[i]);

	dp1[0] = a[0]; dp2[0] = slp[0] ? a[0] : 0;
	for (int i = 1; i < n; i++) {
		dp1[i] = dp1[i-1]+a[i];
		if (slp[i]) dp2[i] = dp2[i-1]+a[i];
		else dp2[i] = dp2[i-1];
	}
	
	int ans = dp2[n-1]+dp1[k-1]-dp2[k-1];
	for (int i = k; i < n; i++)
		ans = max(ans, dp2[n-1]+(dp1[i]-dp1[i-k])-(dp2[i]-dp2[i-k]));
		
	printf("%d", ans);
}
