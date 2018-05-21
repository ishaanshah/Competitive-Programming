/* Created by Ishaan Shah on 04-05-2018.
* Problem Name: Xor Again
* Problem Link: https://www.codechef.com/MAY18B/problems/XORAGN
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
			arr[i] *= 2; 
		}
		int res = arr[0];
		for(int i = 1; i < n; i++) {
			res ^= arr[i];
		}
		cout << res << endl;
	}
}