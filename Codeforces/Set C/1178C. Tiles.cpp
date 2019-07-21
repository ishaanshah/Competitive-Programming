/* Created by Ishaan Shah on 20-07-2019.
* Problem Name: Tiles
* Problem Link: https://codeforces.com/contest/1178/problem/C
*/

#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define MOD 998244353

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

ll bin_exp(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    ll w, h;
    cin >> w >> h;
    cout << bin_exp(2, w+h, MOD);
}