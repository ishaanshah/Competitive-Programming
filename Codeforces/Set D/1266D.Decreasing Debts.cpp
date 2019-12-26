/* Created by Ishaan Shah on 18-12-2019.
* Problem Name: Decreasing Debts
* Problem Link: http://codeforces.com/contest/1266/problem/D
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ff first
#define ss second
#define sz(a) ll((a).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(), (c).end()

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector <ll> vi;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    ll n, m;
    cin >> n >> m;

    vector<ii> arr(n, {0, 0});
    for (ll i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        arr[u-1].ff += w; arr[u-1].ss = u;
        arr[v-1].ff -= w; arr[v-1].ss = v;
    }

    sort(all(arr));

    ll lo = 0, hi = n-1;
    vector <pair<ll, pair<ll, ll> > > ans;
    while (lo < hi) {
        ll z = min(-arr[lo].ff, arr[hi].ff);
        if (z) {
            arr[lo].ff += z;
            arr[hi].ff -= z;
            ans.pb(mp(arr[hi].ss, mp(arr[lo].ss, z)));   
        }
        if (arr[lo].ff == 0)
            lo++;
        else
            hi--;
    }

    cout << ans.size() << '\n';
    for (ll i = 0; i < ans.size(); i++)
        cout << ans[i].ff << ' ' << ans[i].ss.ff << ' ' << ans[i].ss.ss << '\n';

    return 0;
}