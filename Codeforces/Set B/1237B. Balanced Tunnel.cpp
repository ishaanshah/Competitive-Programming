/* Created by Ishaan Shah on 17-10-2019.
* Problem Name: Balanced Tunnel
* Problem Link: https://codeforces.com/contest/1237/problem/B
*/

#include <bits/stdc++.h>

#define REP(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define MOD 1000000007

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

ll power(ll x, ll y) {
    ll res = 1;
    while (y) {
        if (y&1)
            res = (res%MOD*x%MOD)%MOD;
        x = (x%MOD * x%MOD)%MOD;
        y >>= 1;
    }
    return res;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    ll n, m;
    cin >> n >> m;
    ll ans = power(2, m)-1;
    ans = power(ans, n);
    cout << ans;
}