/* Created by Ishaan Shah on 22-01-2019.
* Problem Name: Swap Adjacent Elements
* Problem Link: https://codeforces.com/problemset/problem/920/C
*/

#include <bits/stdc++.h>

using namespace std;

bool res = true;
int n, a[200005], dp[200005];
string s;

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	cin >> s;

	dp[0] = 0;
	for (int i = 1; i <= n; i++) dp[i] = dp[i-1] + (s[i - 1]-'0');
	
	for (int i = 1; i <= n; i++) {
		if(a[i] < i) {
			if(i-a[i] != dp[i-1] - dp[a[i]-1]) {
				res = false;
				break;
			}
		} else {
			if(a[i]-i != dp[a[i]-1] - dp[i-1]) {
				res = false;
				break;
			}
		}
	}
	
	if (res) printf("YES");
	else printf("NO");
}
