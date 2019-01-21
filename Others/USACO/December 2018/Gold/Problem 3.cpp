/* Created by Ishaan Shah on 21-01-2019.
* Problem Name: Teamwork
* Problem Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=863
*/

#include <bits/stdc++.h>

using namespace std;

int n, k;
int arr[10005], dp[10005];

int main() {
	freopen("teamwork.in", "r", stdin);
	freopen("teamwork.out", "w", stdout);
	
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	dp[0] = arr[0];
	for (int i = 1; i < n; i++) {
		dp[i] = 0;
		int mx = arr[i];
		for(int j = i; j >= 0 && i+1-j <= k; j--) {
			mx = max(mx, arr[j]);
			if(j == 0) dp[i] = max(dp[i], mx*(i+1-j));
			else dp[i] = max(dp[i], dp[j-1] + mx*(i+1-j));
		}
	} 
	printf("%d", dp[n-1]);
}
