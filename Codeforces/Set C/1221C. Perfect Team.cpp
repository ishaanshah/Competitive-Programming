/* Created by Ishaan Shah on 19-09-2019.
* Problem Name: Perfect Team
* Problem Link: https://codeforces.com/contest/1221/problem/C
*/

#include <bits/stdc++.h>

#define REP(i, a, b) for(ll i = (ll)a; i < (ll)b; i++)

using namespace std;

typedef long long ll;
typedef vector <ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    ll q;
    cin >> q;
    while (q--) {
        ll m, c, x;
        cin >> m >> c >> x;
        ll bar = min(m, min(c, x));
        ll ans = bar;
        x -= bar;
        c -= bar;
        m -= bar;
        if ((c >= m && 2*m >= c) || (m >= c && 2*c >= m)) {
            ans += (c+m)/3;
        } else {
            ans += min(c, m);
        }
        cout << ans << '\n';
    }
}