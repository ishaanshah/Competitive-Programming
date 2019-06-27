/* Created by Ishaan Shah on 13-06-2019.
* Problem Name: Road Signs
* Problem Link: https://www.codechef.com/JUNE19B/problems/RSIGNS
*/

#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

typedef long long ll;

ll power(ll x, ll y, ll p) { 
    ll res = 1;
    x = x % p; 
    while (y > 0) {  
        if (y & 1)
            res = (res*x) % p;  
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    
    ll t;
    cin >> t;
    while (t--) {
        ll k;
        cin >> k;
        ll res = power(2, k, MOD);
        res = ((res % MOD) * 5) % MOD;
        cout << res << endl;
    }
}
