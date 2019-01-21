/* Created by Ishaan Shah on 13-01-2019.
* Problem Name: Covention
* Problem Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=858
*/

#include <bits/stdc++.h>
#define MAX_T 1e9+1

using namespace std;

int m, c, n;
int at[100005];

bool check(int t) {
	int j = 0, b_used = 0, strt, wait;
	while (j < n) {
		strt = at[j];
		for (int i = 0; i < c; i++) {
			wait = at[j] - strt;
			if (wait > t) {
				break;
			}
			j++;
			if (j >= n) break; 
		}
		b_used++;
	}
	if (b_used > m) return false;
	else return true;
}

int main() {
	freopen("convention.in", "r", stdin);
	freopen("convention.out", "w", stdout);
	
	scanf("%d %d %d", &n, &m, &c);
	
	for (int i = 0; i < n; i += 1) scanf("%d", &at[i]);
	
	sort(at, at+n);
	int lo = 0, hi = MAX_T, mid, ans;
	while (hi >= lo) {
		mid = (hi+lo)/2;
		if (check(mid)) {
			ans = mid;
			hi = mid-1;
		} else {
			lo = mid+1;
		}
	}
	
	printf("%d", ans);	
}
