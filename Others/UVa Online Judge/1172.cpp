/* Created by Ishaan Shah on 01-07-2018.
* Problem Name: The Bridges of Kölsberg
* Problem Link: https://uva.onlinejudge.org/external/11/1172.pdf
*/

/* Note that outputs of uDebug and output given by the following code match but UVa OJ is giving Wrong Answer*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string osb[1005], onb[1005];
ll tsb[1005], tnb[1005];
ll memo[1005][1005];
int visited[1005][1005];
int nb, sb;
int cnt;

ll dp(int i, int j) {
	if (i == nb || j == sb) return 0;
	ll &ans = memo[i][j];
	if (visited[i][j]) return ans;
	visited[i][j] = 1;
	ans = 0;
	int t1, t2, t3;
	if (onb[i] == osb[j]) ans = max(ans, dp(i+1, j+1) + tnb[i] + tsb[j]);
	else ans = max(ans, dp(i+1, j+1));
	ans = max(ans, dp(i+1, j));
	ans = max(ans, dp(i, j+1));
	return ans;
}

void count(int i, int j) {
	if (i == nb || j == sb) return;
	if (memo[i][j] == dp(i+1, j+1) + tnb[i] + tsb[j]) {
		cnt++;
		count(i+1, j+1);
	} else if (memo[i][j] == dp(i+1, j+1)) count(i+1, j+1); 
	else if (memo[i][j] == dp(i+1, j)) count(i+1, j);
	else count(i, j+1);
}

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--) {
		cnt = 0;
		memset(visited, 0, sizeof visited);
		scanf("%d", &nb);
		string temp;
		for (int i = 0; i < nb; i += 1) 
			cin >> temp >> onb[i] >> tnb[i];
		scanf("%d", &sb);
		for (int i = 0; i < sb; i += 1) 
			cin >> temp >> osb[i] >> tsb[i];
		dp(0, 0); 
		count(0,0);
		printf("%lld %d\n", dp(0, 0), cnt);
	}
}
