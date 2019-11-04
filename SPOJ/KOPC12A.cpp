/* Created by Ishaan Shah on 14-10-2019.
* Problem Name: Building Construction
* Problem Link: https://www.spoj.com/problems/KOPC12A/
*/

#include <bits/stdc++.h>

#define REP(i, a, b) for(int i = (int)a; i < (int)b; i++)

using namespace std;

typedef long long ll;

int n;

ll f(int th, vector<ll> &h, vector<ll> &c) {
    ll ans = 0;
    for (int i = 0; i < n; i++)
        ans += abs(h[i]-th)*c[i];
    
    return ans;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<ll> h(n), c(n);
        for (int i = 0; i < n; i++)
            cin >> h[i];
        for (int i = 0; i < n; i++)
            cin >> c[i];
        int hi = 10005, lo = 0, mid1, mid2;
        while (hi - lo > 3) {
            mid1 = lo + (hi-lo)/3;
            mid2 = hi - (hi-lo)/3;
            if (f(mid1, h, c) > f(mid2, h, c))
                lo = mid1;
            else
                hi = mid2;
        }
        ll ans = 1e15;
        for (; lo <= hi; lo++)
            ans = min(ans, f(lo, h, c));
        cout << ans << '\n';
    }
}