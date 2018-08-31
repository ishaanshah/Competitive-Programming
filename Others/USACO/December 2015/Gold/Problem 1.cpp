/* Created by Ishaan Shah on 31-08-2018.
* Problem Name: High Card Low Card (Gold)
* Problem Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=573 
*/

#include<bits/stdc++.h>

using namespace std;
 
int n, ans = 0;
set<int> unused;
int hi[100005], lo[100005];

int main() {
	freopen("cardgame.in", "r", stdin);
	freopen("cardgame.out", "w", stdout);
	
	scanf("%d", &n);
	for (int i = 0; i < 2*n; i++) unused.insert(i+1);
	for (int i = 0; i < n/2; i++) {
		int x;
		scanf("%d", &x);
		unused.erase(x);
		hi[i] = x;
	}
	sort(hi, hi+n/2);
	for (int i = n/2; i < n; i++) {
		int x;
		scanf("%d", &x);
		unused.erase(x);
		lo[i-n/2] = x;
	}
	sort(lo, lo+n/2, greater<int>());
	set <int> unused2;
	for (int i = 0; i < n/2; i++) {
		auto it = unused.begin();
		unused2.insert(*it);
		it = next(it);
		unused.erase(*prev(it));
	}
	
	for (int i = 0; i < n/2; i++) {
		if (unused.lower_bound(hi[i]) != unused.end()) {
			ans++;
			unused.erase(*unused.lower_bound(hi[i]));
		}
	}
	for (int i = 0; i < n/2; i++) {
		if (unused2.lower_bound(lo[i]) != unused2.begin()) {
			ans++;
			unused2.erase(*(prev(unused2.lower_bound(lo[i]))));
		}
	}
	printf("%d", ans);
}
