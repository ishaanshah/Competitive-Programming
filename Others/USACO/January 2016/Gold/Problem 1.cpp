/* Created by Ishaan Shah on 04-09-2018.
* Problem Name: Angry Cows
* Problem Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=597
*/

#include <bits/stdc++.h>

using namespace std;

int n;
set<int> loc;

bool checkl(int s, int r) {
	if (*loc.begin() < s-r) {
		int curr = *loc.lower_bound(s-r), last;
		r -= 2;
		while (curr != *loc.begin()) {
			last = curr;
			curr = *loc.lower_bound(curr-r);
			if (curr >= last) return false;
			r -= 2;
		}
	}
	return true;
}

bool checkr(int s, int r) {
	if (*loc.rbegin() > s+r) {
		int curr = *prev(loc.upper_bound(s+r)), last;
		r -= 2;
		while (curr != *loc.rbegin()) {
			last = curr;
			curr = *prev(loc.upper_bound(curr+r));
			if (curr <= last) return false;
			r -= 2;
		}
	}	
	return true;
}

int main() {
	freopen("angry.in", "r", stdin);
	freopen("angry.out", "w", stdout);

	scanf("%d", &n);
	int x;
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		loc.insert(2*x);
	}

	int lo = 0, hi = *loc.rbegin()-*loc.begin(), mid;
	while (hi != lo) {
		mid = (hi+lo)/2;
		int l = *loc.begin(), r = *loc.rbegin(), m;
		while (l < r) {
			m = (l+r+1)/2;
			if (checkl(m, mid)) l = m;
			else r = m-1;
		}
		if (checkr(l, mid)) hi = mid;
		else lo = mid+1;		
	}
	printf("%.1lf", lo/2.0);
}
