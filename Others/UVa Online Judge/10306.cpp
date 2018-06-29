/* Created by Ishaan Shah on 28-06-2018.
* Problem Name: 
* Problem Link: 
*/

#include <bits/stdc++.h>

#define INF 100000

using namespace std;

int em, n;
int ec[45], tc[45];
int memo[350][350][45];
int visited[350][350][45];

int dp(int i, int j, int k) {
	if (i*i +j*j > em*em || k < 0) return INF;
	if (i*i + j*j == em*em) return 0;
	int &ans = memo[i][j][k];
	if (visited[i][j][k]) return ans;
	visited[i][j][k] = 1;
	ans = min(dp(i, j, k-1), dp(i+ec[k], j+tc[k], k) + 1);
	return ans;
}

int main() {
	//freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d", &n, &em);
		memset(visited, 0, sizeof visited);
		int ans = INF;
		for (int i = 0; i < n; i += 1) {
			scanf("%d %d", &ec[i], &tc[i]);
		}
		ans = dp(0, 0, n-1);
		if (ans == INF) printf("not possible\n");
		else printf("%d\n", ans);
	}
}	
