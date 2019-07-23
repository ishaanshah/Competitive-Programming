/* Created by Ishaan Shah on 23-07-2019.
* Problem Name: Birthday Gift Again
* Problem Link: https://www.codechef.com/COOK108B/problems/BDGFT
*/

#include <bits/stdc++.h>

#define REP(i, a, b) for(ll i = a; i < b; i++)

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        ll ans = 0;
        ll cnt0[s.size()], cnt1[s.size()];
        if (s[0] == '1') {
            cnt1[0] = 1;
            cnt0[0] = 0;
        } else {
            cnt0[0] = 1;
            cnt1[0] = 0;
        }
        REP(i, 1, (ll)s.size()) {
            if (s[i] == '1') {
                cnt1[i] = cnt1[i-1]+1;
                cnt0[i] = cnt0[i-1];
            } else {
                cnt0[i] = cnt0[i-1]+1;
                cnt1[i] = cnt1[i-1];
            }
        }
        for (ll x = 1; x*x+x <= (ll)s.size(); x++) {
            ll size = x+x*x;
            ll c0, c1;
            c0 = cnt0[size-1]; c1 = cnt1[size-1];
            if (c0 == c1*c1) ans++;
            ll start = 0, end = size;
            while (end < (ll)s.size()) {
                c0 = cnt0[end]-cnt0[start];
                c1 = cnt1[end]-cnt1[start];
                if (c0 == c1*c1) ans++;
                end++, start++;
            }
        }
        cout << ans << endl;
    }    
}