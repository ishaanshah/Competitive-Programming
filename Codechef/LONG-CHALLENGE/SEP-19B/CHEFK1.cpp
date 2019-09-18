/* Created by Ishaan Shah on 11-09-2019.
* Problem Name: Chef Designed a Network
* Problem Link: https://www.codechef.com/SEPT19B/problems/CHEFK1
*/

#include <bits/stdc++.h>s

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

    int t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        ll ans;
        if (n == 1) {
            if (m == 1) cout << 1;
            else if (m == 0) cout << 0;
            else cout << -1;
            cout << '\n';
            continue;
        }
        if (n == 2) {
            if (m == 1) cout << 1;
            else if (m == 2 || m == 3) cout << 2;
            else cout << -1;
            cout << '\n';
            continue;
        }
        if (m < n-1 || m > n*(n+1)/2) 
            ans = -1;
        else if (m == n-1 || m == n || m == 1+n)
            ans = 2;
        else if (n+1 < m && m <= 2*n)
            ans = 3;
        else
            ans = ceil(2.0*((long double)m-2.0*(long double)n)/(long double)n) + 3;

        cout << ans << '\n';
    }
}