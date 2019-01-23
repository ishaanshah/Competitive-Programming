/* Created by Ishaan Shah on 23-01-2019.
* Problem Name: Python Indentation
* Problem Link: https://codeforces.com/problemset/problem/909/C
*/

#include <bits/stdc++.h>

#define mod 1000000007

using namespace std;

int n, dp[5005][5005];
char s[5005];

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) cin >> s[i];
	
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		if (s[i-1] == 'f') {
			for (int j = 0; j < i; j++) dp[i][j+1] = dp[i-1][j];
		} else {
			int sum = 0;
			for (int j = i-1; j >= 0; j--) {
				sum = (sum + dp[i-1][j])%mod;
				dp[i][j] = sum;
			} 
		}
	}
	
	int ans = 0;
	for (int i = 0; i < 5005; i++) ans = (dp[n-1][i]+ans)%mod;
	printf("%d", ans);
}
