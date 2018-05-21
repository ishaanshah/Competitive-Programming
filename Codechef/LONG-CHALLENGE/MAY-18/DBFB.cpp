/* Created by Ishaan Shah on 06-05-2018.
* Problem Name: Dibs on Fibs
* Problem Link: https://www.codechef.com/MAY18B/problems/DBFB
*/

#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007

int main()
{
	#ifndef ONLINE_JUDGE
    	freopen("input.in", "r", stdin);
    	freopen("output.out", "w", stdout);
	#endif

	long long t;
	cin >> t;
	while(t--) {
		long long n, m;
		cin >> m >> n;
		long long a[m], b[m];
		for(long long i = 0; i < m; i++) {
			cin >> a[i];
		}
		for(long long i = 0; i < m; i++) {
			cin >> b[i];
		}
		sort(a, a+m);
		sort(b, b+m);
		long long result;
		if(n == 1) {
			long long f = a[0];
			result = (((f*m) % mod) * m % mod);
			for(int i = 1; i < m; i++) {
				result += (m*(a[i]-a[0])) % mod;
			}
		} else {
			long long fa[n];
			fa[0] = 1;
			fa[1] = 0;
			for(long long i = 2; i < n; i++) {
				fa[i] = (fa[i-1] + fa[i-2]) % mod;
			}

			long long fb[n];
			fb[0] = 0;
			fb[1] = 1;
			for(long long i = 2; i < n; i++) {
				fb[i] = (fb[i-1] + fb[i-2]) % mod;
			}

			long long fib = ((fb[n-2]*a[0]) % mod + (fb[n-1]*b[0]) % mod) % mod;
		
			result = ((fib*m) % mod * m) % mod;
			for(long long i = 1; i < m; i++) {
				result += (((m*fb[n-1]) % mod)*(b[i]-b[0])) % mod;
				result += (((m*fa[n-1]) % mod)*(a[i]-a[0])) % mod;
			}
		}
		cout << result % mod << endl;
	}
}