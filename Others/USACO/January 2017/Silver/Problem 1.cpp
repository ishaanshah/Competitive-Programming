/* Created by Ishaan Shah on 09-09-2018.
* Problem Name: Cow Dance Show
* Problem Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=690
*/

#include <bits/stdc++.h>

using namespace std;

int n, t;
int d[10005];

bool check(int k) {
	int tc = 0;
	priority_queue<int, vector<int>, greater<int> > pq;
	for (int i = 0; i < k; i++) pq.push(d[i]);
	int i = k;
	while (tc < t) {
		tc++;
		while (!pq.empty() && tc == pq.top()) pq.pop();
		while (pq.size() < k && i < n) {
			pq.push(d[i]+tc);
			i++;
		}
	}
	if (pq.empty()) return true;
	else return false;
}

int main() {
	freopen("cowdance.in", "r", stdin);
	freopen("cowdance.out", "w", stdout);
	
	scanf("%d %d", &n, &t);
	for (int i = 0; i < n; i += 1) scanf("%d", &d[i]);
	
	int lo = 0, hi = n+1, mid;
	while (lo < hi) {
		mid = (lo+hi)/2;
		if (check(mid)) {
			hi = mid;
		} else {
			lo = mid+1;
		}
	}
	printf("%d", mid);
}
