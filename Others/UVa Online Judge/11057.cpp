/* Created by Ishaan Shah on 30-07-2018.
* Problem Name: Exact Sum
* Problem Link: https://uva.onlinejudge.org/external/110/11057.pdf
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	
	int n, sum;
	while (scanf("%d", &n) != EOF) {
		int arr[n];
		for (int i = 0; i < n; i += 1) scanf("%d", &arr[i]);
		scanf("%d", &sum);
		sort(arr, arr+n);
		pair <int, int> ans;
		int mn = 1000000;
		for (int i = 0; i < n; i++) {
			int s = sum - arr[i];
			int idx = upper_bound(arr, arr+n, s) - arr - 1;
			if ((idx < 0) || (idx == i) || (arr[idx] != s)) continue;
			else {
				if (abs(arr[i]-s) < mn) {
					mn = abs(arr[i]-s);
					ans.first = min(arr[i], s);
					ans.second = sum - ans.first;
				}
			}
		}
		printf("Peter should buy books whose prices are %d and %d.\n\n", ans.first, ans.second);
	}
}
