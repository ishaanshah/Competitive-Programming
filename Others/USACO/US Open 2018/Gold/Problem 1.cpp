/* Created by Ishaan Shah on 07-07-2018.
* Problem Name: Out of Sorts
* Problem Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=837
*/

#include <bits/stdc++.h>

using namespace std;

int B[100005];
int N;
pair<int, int> A[100005];

void modify(int j) { 
	for (; j <= N; j += (j&-j)) B[j]++; 
}

int prefix_sum(int j) { 
	int sum = 0; 
	for (; j > 0; j -= (j&-j)) sum += B[j]; 
	return sum; 
}

int main() {
	freopen("sort.in", "r", stdin);
	freopen("sort.out", "w", stdout);
	scanf("%d", &N);
	for (int i = 1; i <= N; i += 1) {
		scanf("%d", &A[i].first);
		A[i].second = i;
	}	
	sort(A+1, A+N+1);
	int ans = 1;
	for (int i = 1; i < N; i++) {
		modify(A[i].second);
		ans = max(ans, i-prefix_sum(i));
	}
	printf("%d", ans);
}
