/* Created by Ishaan Shah on 08-09-2019.
* Problem Name: Ivnat and Aliens
* Problem Link: https://codeforces.com/group/yny9prUF8z/contest/252289/problem/B
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
 
    ll a, b;
    cin >> a >> b;
    ll arr[6];
    REP(i, 0, 6) cin >> arr[i];
    ll ans = 1e18;
    ll loc = 0;
    REP(i, 0, 6) {
        ll tmp = 0;
        REP(j, 0, 6) {
            ll dist = abs(arr[i]-arr[j]);
            if(dist%3 != 0) tmp += min(a, b);   
        }
        if (ans > tmp) {
            loc = arr[i];
            ans = tmp;
        }
    }
    cout << ans << '\n' << loc;
}