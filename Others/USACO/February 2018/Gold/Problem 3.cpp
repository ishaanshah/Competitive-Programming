/* Created by Ishaan Shah on 25-06-2018.
* Problem Name: Taming the Herd
* Problem Link: http://usaco.org/index.php?page=viewproblem2&cpid=815
*/

#include <bits/stdc++.h>

#define INF 10000

using namespace std;

int n;
int arr[105];
int visited[105][105][105];
int memo[105][105][105];

int dp(int rem, int i, int day) {
	if (n-i < rem) return INF; 
	if (i == n) return 0;
	int &ans = memo[rem][i][day];
	if (visited[rem][i][day]) return ans;
	visited[rem][i][day] = 1;
	if (rem == 0) ans = dp(rem, i+1, day+1) + (arr[i] == day ? 0:1);
	else ans = min(dp(rem, i+1, day+1) + (arr[i] == day ? 0:1), dp(rem-1, i+1, 1) + (arr[i] == 0 ? 0:1));
	return ans;
}

int main() {
	freopen("taming.in", "r", stdin);
	freopen("taming.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i += 1) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n; i++) {
		printf("%d\n", dp(i, 1, 1) + (arr[0] == 0 ? 0:1));
	}
}
