/* Created by Rutvij Menavlikar on 27-09-2019.
* Problem Name: Good Sets
* Problem Link: https://www.codechef.com/ACMIND16/problems/ICPC16D
*/

#include <bits/stdc++.h>

using namespace std;

const int max_n = (75e4) + 5;
const int mod = (1e9) + 7;

int t,n;
int a[max_n];
long long dp[max_n] = {0};
int m,s;

int main() {
	cin >> t;
	for(int z=0;z<t;++z) {
		cin >> n;
		for(int i=0;i<n;++i) {
			cin >> a[i];
			dp[a[i]] = 1;
		}
		sort(a,a+n);
		m = a[n-1];
		for(int i=0;i<(n-1);++i) {
			for(int j=2;(a[i] * j) <= m;++j) {
				s = a[i] * j;
				dp[s] = (dp[s] + dp[a[i]]) % mod;
			}
		}
		m = 0;
		for(int i = 0;i<n;++i)
			m = (m + dp[a[i]]) % mod;
		cout << m << endl;
		for(int i=0;i<(75e4);++i)
			dp[i] = 0;
	}
	return 0;
}