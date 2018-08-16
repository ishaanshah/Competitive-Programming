/* Created by Ishaan Shah on 16-08-2018.
* Problem Name: Why Did the Cow Cross the Road(Silver)
* Problem Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=714
*/

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int h, c;
multiset<int> hen;
pi cow[20005];

int main() {
	freopen("helpcross.in", "r", stdin);
	freopen("helpcross.out", "w", stdout);

	scanf("%d %d", &h, &c);
	for (int i = 0; i < h; i += 1) {
		int x;
		scanf("%d", &x);
		hen.insert(x);
	}
	for (int i = 0; i < c; i += 1) scanf("%d %d", &cow[i].second, &cow[i].first);
	
	sort(cow, cow+c);	
	int ans = 0;
	for (int i = 0; i < c; i++) {
		auto it = hen.lower_bound(cow[i].second);
		if (*it <= cow[i].first && it != hen.end()) {
			ans++;
			hen.erase(it);
		}
	}
	printf("%d", ans);
}
