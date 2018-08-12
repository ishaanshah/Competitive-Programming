/* Created by Ishaan Shah on 12-08-2018.
* Problem Name: Hoof, Paper, Scissors
* Problem Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=694
*/

#include <bits/stdc++.h>

#define INF 1e9

using namespace std;

int N, K;
int arr[100005];
int memo[100005][25][3], visited[100005][25][3];

int dp(int i, int k, int g) {
	if (k < 0) return -INF;
	if (i == N) return 0;
	
	int &ans = memo[i][k][g];
	if (visited[i][k][g]) return ans;
	visited[i][k][g] = 1;
	if (g == 0) {
		ans = max(dp(i+1, k-1, 1), max(dp(i+1, k-1, 2), dp(i+1, k, 0)));
		if (arr[i] == 1) ans++;
	} else if (g == 1) {
		ans = max(dp(i+1, k-1, 0), max(dp(i+1, k-1, 2), dp(i+1, k, 1)));
		if (arr[i] == 2) ans++;
	} else {
		ans = max(dp(i+1, k-1, 0), max(dp(i+1, k-1, 1), dp(i+1, k, 2)));
		if (arr[i] == 0) ans++;
	}
	return ans;
}

int main() {
	freopen("hps.in", "r", stdin);
	freopen("hps.out", "w", stdout);
	
	memset(visited, 0, sizeof visited);
	scanf("%d %d", &N, &K);
	string t;
	for (int i = 0; i < N; i++) {
		cin >> t;
		if (t == "H") arr[i] = 0;
		else if (t == "S") arr[i] = 1;
		else arr[i] = 2; 
	}
	int ans = max(dp(0, K, 0), max(dp(0, K, 1), dp(0, K, 2)));
	printf("%d", ans);
}
