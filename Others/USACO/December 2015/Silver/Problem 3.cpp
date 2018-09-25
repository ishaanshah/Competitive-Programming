/* Created by Ishaan Shah on 24-09-2018.
* Problem Name: Breed Counting 
* Problem Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=572
*/

#include <bits/stdc++.h>

using namespace std;

int n, q;
int t[100005];
int cnt[3][100005];

int main() {
	freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout);
	
	scanf("%d %d", &n, &q);
	cnt[0][0] = 0; cnt[1][0] = 0; cnt[2][0] = 0;
	scanf("%d", &t[0]);
	t[0]--;
	cnt[t[0]][0]++;
	for (int i = 1; i < n; i++) {
		scanf("%d", &t[i]);
		t[i]--;
		cnt[t[i]][i] = cnt[t[i]][i-1]+1;
		cnt[(t[i]+1)%3][i] = cnt[(t[i]+1)%3][i-1];
		cnt[(t[i]+2)%3][i] = cnt[(t[i]+2)%3][i-1];
	}
	int a, b;
	for (int i = 0; i < q; i++) {
		scanf("%d %d", &a, &b);
		a--; b--;
		int t0 = cnt[0][b]-cnt[0][a] + ((t[a] == 0) ? 1: 0);
		int t1 = cnt[1][b]-cnt[1][a] + ((t[a] == 1) ? 1: 0);
		int t2 = cnt[2][b]-cnt[2][a] + ((t[a] == 2) ? 1: 0);
		printf("%d %d %d\n", t0, t1, t2);
	}
}
