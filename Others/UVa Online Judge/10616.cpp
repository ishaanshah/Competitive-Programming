/* Created by Ishaan Shah on 19-06-2018.
* Problem Name: Divisible Group Sums
* Problem Link: https://uva.onlinejudge.org/external/106/10616.pdf
*/

#include <bits/stdc++.h>

#define MAX_N 205
#define MAX_D 25
#define MAX_M 15

using namespace std;

typedef long long ll;

int D, N, M;
ll arr[MAX_N];
ll memo[MAX_N][MAX_D][MAX_M];
bool visited[MAX_N][MAX_D][MAX_M];

ll dp(int i, int j, int m) {
	if(m == M) {
		if(j == 0) return 1;
		return 0;
	}
	if(i == N) return 0;
	ll &ans = memo[i][j][m];
	if(visited[i][j][m]) return ans;
	visited[i][j][m] = true;
	ll a = dp(i+1, ((j+arr[i])%D+D)%D, m+1);
	ll b = dp(i+1, j, m);
	ans = a+b;
	return ans;
} 

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	int q;
	int tc = 1;
	while (scanf("%d %d", &N, &q)) {
		for (int i = 0; i < N; i += 1) {
			scanf("%lld", &arr[i]);
		}
		if(!N && !q) break;
		printf("SET %d:\n", tc);
		for (int i = 1; i <= q; i += 1) {
			scanf("%d %d", &D, &M);
			memset(visited, false, sizeof(visited));
			ll ans = dp(0, 0, 0);
			printf("QUERY %d: %lld\n", i, ans);
		}
		tc++;
	}
}
