/* Created by Ishaan Shah on 21-08-2018.
* Problem Name: Why Did the Cow Cross the Road II(Silver)
* Problem Link: http://www.usaco.org/index.php?page=viewproblem2&cpid=715
*/

#include <bits/stdc++.h>

#define INF 1e9

using namespace std;

int n, b, k;
int a[100005];

int main() {
	freopen("maxcross.in", "r", stdin);
	freopen("maxcross.out", "w", stdout);
	
	scanf("%d %d %d", &n, &k, &b);
	for (int i = 0; i < b; i++) scanf("%d", &a[i]);
	a[b] = 1; a[b+1] = n;	
	sort(a, a+b+2);
	
	// Handle edge case
	if (a[1] - 1 >= k || n - a[b] >= k) {
		printf("0");
		return 0;
	}
	
	int i = 0, j = 2, ans = INF;
	while (i < b+2 && j < b+2) {
		if (max(a[j]-a[i]-1, 1) >= k) {
			ans = min(ans, j-i-1);
			i++;
		} else {
			j++;
		}
	}
	printf("%d", ans);
}
