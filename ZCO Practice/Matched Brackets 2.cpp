/* Created by Ishaan Shah on 26-11-2018.
* Problem Name: Matched Brackets 2
* Problem Link: https://www.codechef.com/ZCOPRAC/problems/ZCO12003
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.in", "r", stdin);
		freopen("output.out", "w", stdout);
	#endif
	
	int n;
	scanf("%d", &n);
	int brk[n];
	for (int i = 0; i < n; i++) scanf("%d", &brk[i]);
	int ans = 1;
	stack<pair<int, int> >stk;
	for (int i = 0; i < n; i++) {
		if (stk.empty()) {
			stk.push({brk[i], 1});
			continue;
		}
		if (stk.top().first == brk[i]) {
			stk.push({brk[i], stk.top().second});
			continue;
		}
		if (brk[i] == 2 || brk[i] == 4) {
			stk.pop();
			continue;
		}
		stk.push({brk[i], stk.top().second+1});
		ans = max(ans, stk.top().second);
	}
	cout << ans << " ";

	int ans1 = 1, ans2 = 1;
	stack<pair<int, int> > stk1, stk2;
	for (int i = 0; i < n; i++) {
		if (brk[i] == 1) {
			stk1.push({brk[i], i});
			continue;
		}
		if (brk[i] == 3) {
			stk2.push({brk[i], i});
			continue;
		}
		if (brk[i] == 2) {
			ans1 = max(i-stk1.top().second, ans1);
			stk1.pop();
			continue;
		}
		if (brk[i] == 4) {
			ans2 = max(i-stk2.top().second, ans2);
			stk2.pop();
			continue;
		}
	}
	cout << ans1+1 << " " << ans2+1;
}
