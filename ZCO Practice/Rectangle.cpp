/* Created by Ishaan Shah on 25-11-2018.
* Problem Name: Rectange
* Problem Link: https://www.codechef.com/ZCOPRAC/problems/ZCO15004
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.in", "r", stdin);
		freopen("output.out", "w", stdout);
	#endif
	
	int n;
	pair<int, int> pts[100005];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d %d", &pts[i].first, &pts[i].second);
	sort(pts, pts+n);
	pts[n] = {100000, 500};
	
	int area = 0;
	for (int i = 1; i <= 500; i++) {
		int j = 0;
		int left = 0;
		while (j <= n) {
			if (pts[j].second >= i) 
				area = max(area, (pts[j].first-left)*i);
			else {
				area = max(area, (pts[j].first-left)*i);
				left = pts[j].first;
			}
			j++;
		}
	}
	
	cout << area;
}
