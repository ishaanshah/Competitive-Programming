/* Created by Ishaan Shah on 26-06-2019.
* Problem Name: Computer Game
* Problem Link: https://codeforces.com/contest/1183/problem/C
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll k, n, a, b;

bool chk (ll mid) {
    ll k_c = k-mid*a;
    ll n_c = n-mid;
    if (k_c-n_c*b > 0) return true;
    else return false;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t;
    cin >> t;
    while (t--) {
        cin >> k >> n >> a >> b;
        ll ans = -1;
        ll lo = 0, hi = n, mid;
        while (lo <= hi) {
            mid = (lo+hi)/2;
            if (chk(mid)) {
                ans = mid;
                lo = mid+1;
            } else {
                hi = mid-1;
            }
        }
        cout << ans << endl;
    }
}