/* Created by Ishaan Shah on 10-07-2018.
* Problem Name: http://www.usaco.org/index.php?page=viewproblem2&cpid=834
* Problem Link: Out of Sorts
*/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

ii A[100005];
int N;

int main() {
	freopen("sort.in", "r", stdin);
	freopen("sort.out", "w", stdout);
	scanf("%d", &N);
	for (int i = 1; i <= N; i += 1) {
		scanf("%d", &A[i].first);
		A[i].second = i;
	}
	sort(A+1, A+N+1, [](ii a, ii b){
		return a.first < b.first || (a.first == b.first && a.second < b.second);
	});	
	int ans = 0;
	for (int i = 1; i < N; i++) {
		ans = max(ans, A[i].second - i);
	}
	printf("%d", ans+1);
}
