/* Created by Ishaan Shah on 01-09-2018.
* Problem Name: Fruit Feast
* Problem Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=574
*/

#include <bits/stdc++.h>

using namespace std;

int t, a, b;
int memo[5000005][2], vis[5000005][2];

int dp(int sum, int half) {
	int &ans = memo[sum][half];
	if (vis[sum][half]) return ans;
	vis[sum][half] = 1;
	if (sum+a <= t) ans = dp(sum+a, half);
	else if (sum+a > t && half == 0) ans = max(sum, dp(sum/2, 1));
	else ans = sum;
	
	if (sum+b <= t) ans = max(ans, dp(sum+b, half));
	else if (sum+b > t && half == 0) ans = max(ans, max(sum, dp(sum/2, 1)));
	else ans = max(ans, sum);
	
	return ans;
}

int main() {
	freopen("feast.in", "r", stdin);
	freopen("feast.out", "w", stdout);
	
	scanf("%d %d %d", &t, &a, &b);
	int ans = dp(0, 0);
	printf("%d", ans);
}
