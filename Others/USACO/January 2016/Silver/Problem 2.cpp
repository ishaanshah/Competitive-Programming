/* Created by Ishaan Shah on 01-10-2018.
* Problem Name: Subsequences Summing to Sevens
* Problem Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=595
*/

#include <bits/stdc++.h>

using namespace std;

int n, arr[100005];
vector<int> idx[7];

int main() {
	freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout);
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum = (sum+(arr[i]%7))%7;
		idx[sum].push_back(i);
	}
	int ans = 0;
	for (int i = 0; i < 7; i++) {
		if (!idx[i].empty()) ans = max(ans, *prev(idx[i].end())-*idx[i].begin());
	}
	printf("%d", ans);
}
