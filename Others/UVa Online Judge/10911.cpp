/* Created by Ishaan Shah on 22-07-2018.
* Problem Name: Forming Quiz Teams
* Problem Link: http://uva.onlinejudge.org/external/109/10911.pdf
*/

#include <bits/stdc++.h>

#define INF 10e5

using namespace std;

int n;
int x[20], y[20];
double memo[70000]; 
int visited[70000];

int cnt(int num) {
	for (int i = 0; i < 2*n; i += 1)
		if (!((num >> i) & 1)) return i;
}

int st(int num, int i, int j) {
	num = (1 << i) | num;
	num = (1 << j) | num;
	return num;
}

double dp(int num) {
	if (num == pow(2, 2*n)-1) return 0;
	double &ans = memo[num];
	if (visited[num]) return ans;
	visited[num] = 1;
	int t = cnt(num);
	ans = INF;
	for(int i = t+1; i < 2*n; i++) {
		if(!(num >> i & 1)) {
			ans = min(dp(st(num, i, t)) + sqrt(pow(x[i]-x[t], 2) + pow(y[i]-y[t], 2)), ans);
		}
	}
	return ans;
}

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	
	int c = 0;
	while(scanf("%d", &n)) {
		c++;
		if (n == 0) break;
		memset(visited, 0, sizeof visited);
		string temp;
		for (int i = 0; i < 2*n; i += 1) {
			cin >> temp >> x[i] >> y[i];
		}
		printf("Case %d: %.2f\n", c, dp(0));
	}
}
