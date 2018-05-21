/* Created by Ishaan Shah on 05-05-2018.
* Problem Name: Mighty Friend
* Problem Link: https://www.codechef.com/MAY18B/problems/MTYFRI
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
		int n ,k;
		cin >> n >> k;
		vector<int> m, t, delta;

		int ts = 0; int ms = 0;
		for(int i = 0; i < n; i++) {
			int a;
			if(i%2 == 0) {
				cin >> a;
				ms += a;
				m.push_back(a);
			} else {
				cin >> a;
				ts += a;
				t.push_back(a);
			}
		}
		sort(m.begin(), m.end(), greater<int>());
		sort(t.begin(), t.end());

		for(int i = 0; i < t.size(); i++) {
			delta.push_back(m[i] - t[i]);
		}

		int i = 0;
		while(i < k && i < delta.size()) {
			if(delta[i] > 0) {
				ms -= delta[i];
				ts += delta[i];
			}
			i++;
		}
		if(ms >= ts) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
		}
	}
}