/* Created by Ishaan Shah on 13-10-2019.
* Problem Name: The Football Season
* Problem Link: https://codeforces.com/contest/1244/problem/C
*/

#include <bits/stdc++.h>

#define REP(i, a, b) for(int i = (int)a; i < (int)b; i++)

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

    ll n, p, w, d;
    cin >> n >> p >> w >> d;
    if (p % __gcd(w, d)) {
        cout << -1;
        return 0;
    }
    ll x, y, g;
    g = __gcd(w, d);
    for (x = 0; x < d; x++) {
        if ((x*w)%d == p %d)
            break;
    }
    y = (p-w*x)/d;
    ll l = d/g, r = w/g;
    ll k = min(n, (p/w)-x)/l;
    x += k*l;
    y -= k*r;
    ll z = n-(x+y);
    if (x < 0 || y < 0 || z < 0)
        cout << -1;
    else
        cout << x << ' ' << y << ' ' << z;
}