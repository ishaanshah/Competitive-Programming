/* Created by Ishaan Shah on 26-09-2019.
* Problem Name: Modulo Equality
* Problem Link: https://www.codechef.com/ACMIND17/problems/EQUALMOD
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll max_n = (5e5) + 5;

ll t,n;
ll a[max_n],b[max_n],m[max_n];
ll M;

int main() {
	cin >> t;
	for(int z=0;z<t;++z) {
		cin >> n;
		ll ans1 = 0;
		for(int i=0;i<n;++i)
			cin >> a[i];
		M = (1e18);
		for(int i=0;i<n;++i) {
			cin >> b[i];
			m[i] = a[i] % b[i];
			M = min(M,b[i]);
		}
		for(int i=0;i<n;++i) {
			if(m[i] >= M) {
				ans1 += b[i] - m[i];
				m[i] = 0;
			}
			else if(m[i] != 0)
				ans1 += b[i] - m[i];
		}

		map<ll, vector<ll> > freq;
		set<ll> st;
		for(int i=0;i<n;++i) {
			freq[m[i]].push_back(i);
			st.insert(m[i]);
		}

		ll prev = 0;
		ll ans = ans1;
		for(auto it = st.begin(); it != st.end(); it = next(it)) {
			if(*it == 0)
				continue;
			ans1 += (*it - prev) * n;
			prev = *it;
			ll x = freq[*it].size();
			for(int j = 0;j<x;++j)
				ans1 -= b[freq[*it][j]];
			ans = min(ans,ans1);
		}
		cout << ans << endl;
	}
	return 0;
}