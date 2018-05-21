/* Created by Ishaan Shah on 04-05-2018.
* Problem Name: Minimum Deletions
* Problem Link: https://www.codechef.com/MAY18B/problems/RD19
*/

#include <bits/stdc++.h>

using namespace std;
 
int main()
{
	#ifndef ONLINE_JUDGE
    	freopen("input.in", "r", stdin);
    	freopen("output.out", "w", stdout);
	#endif

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int arr[n];
		for(int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		int res = arr[0];
		for(int i = 1; i < n; i++) {
			res = __gcd(res, arr[i]);
		}

		if(res == 1) {
			cout << 0 << endl;
		} else {
			cout << -1 << endl;
		}
	}
}