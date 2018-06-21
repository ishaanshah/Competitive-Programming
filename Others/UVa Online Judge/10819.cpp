/* Created by Ishaan Shah on 20-06-2018.
* Problem Name: Trouble of 13-Dots
* Problem Link: http://uva.onlinejudge.org/external/108/10819.pdf
*/

#include <bits/stdc++.h>

#define p(i) c[i].first
#define f(i) c[i].second

using namespace std;

int b, n;
pair<int, int> c[10005];
int memo[400005][105][2];
int visited[100005][105][2];


int dp(int sum, int idx, int added) {
	if (idx == n) return 0;
	if (sum == b) return 0;
	
	int &ans = memo[sum][idx][added];
	if (visited[sum][idx][added]) return ans;
	visited[sum][idx][added] = 1;
	if (sum+p(idx) > b) {
		if (sum + p(idx) > 2000 && sum + p(idx) <= b+200 && !added) {
			ans = max(dp(sum, idx+1, added), dp(sum-200+p(idx), idx+1, !added)+f(idx));
		} else {
			ans = dp(sum, idx+1, added);
		}
	} else {
		if (sum+p(idx) > 2000 && !added) {
			ans = max(dp(sum, idx+1, added), dp(sum-200+p(idx), idx+1, !added) + f(idx));
		} else {
			ans = max(dp(sum, idx+1, added), dp(sum+p(idx), idx+1, added) + f(idx));
		}		
	}
	return ans;
}

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	while (scanf("%d %d", &b, &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &p(i), &f(i));
		}
		sort(c, c+n);
		memset(visited, 0, sizeof visited);
		int ans = 0;
		ans = dp(0, 0, 0);
		printf("%d\n", ans);
	}
}
