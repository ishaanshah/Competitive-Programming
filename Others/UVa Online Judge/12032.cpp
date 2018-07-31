/* Created by Ishaan Shah on 31-07-2018.
* Problem Name: The Monkey and the Oiled Bamboo
* Problem Link: https://uva.onlinejudge.org/external/120/12032.pdf
*/

#include <bits/stdc++.h>

using namespace std;

int a[100005];
int n;

bool sim(int k) {
	if (a[0] > k) return false;
	else if (a[0] == k) k--;
	for (int i = 1; i < n; i++) {
		if (a[i]-a[i-1] > k) return false;
		else if (a[i]-a[i-1] == k) k--;
	}
	return true;
}

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	
	int t, cnt = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i += 1) {
			scanf("%d", &a[i]);
		}
		int hi = 100000000, lo = 0, ans = hi+1;
		while (hi >= lo) {
			int mid = (hi+lo)/2;
			if (sim(mid)) {
				ans = mid;
				hi = mid-1;
			} else {
				lo = mid+1;
			}
		}
		printf("Case %d: %d\n", cnt, ans);
		cnt++;
	}
}
