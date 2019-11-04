/* Created by Ishaan Shah on 17-10-2019.
* Problem Name: Balanced Rating Changes
* Problem Link: https://codeforces.com/contest/1237/problem/A
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

    int t;
    cin >> t;
    while (t--) {
        ll a, b, c;
        cin >> a >> b >> c;
        ll ans = 0;
        while (c > 1 && b > 0) {
            b -= 1;
            c -= 2;
            ans += 3;
        }
        while (a > 0 && b > 1) {
            a -= 1;
            b -= 2;
            ans += 3;
        }
        cout << ans << '\n';
    }
}