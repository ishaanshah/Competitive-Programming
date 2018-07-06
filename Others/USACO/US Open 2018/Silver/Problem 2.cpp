/* Created by Ishaan Shah on 06-07-2018.
* Problem Name: 
* Problem Link: 
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("lemonade.in", "r", stdin);
	freopen("lemonade.out", "w", stdout);
	int n;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	sort(arr, arr+n);
	int idx = n;
	int ans = 0;
	for (int i = n-1; i >= 0; i--) {
		if (ans > arr[i]) break;
		ans++;
	}
	printf("%d", ans);
}
