/* Created by Ishaan Shah on 30-08-2019.
* Problem Name: Book Reading
* Problem Link: https://codeforces.com/contest/1213/problem/C
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

    ll q;
    cin >> q;
    while (q--) {
        ll n, m;
        cin >> n >> m;
        ll s10 = 0, arr[10];
        REP(i, 1, 11) {
            s10 += (m*i)%10;
            arr[i-1] = (m*i)%10;
        }
        ll ans = 0;
        ans = (n)/(m*10);
        ans *= s10;
        ll j = (n/(10*m));
        j *= 10*m;
        j = n - j;
        j /= m;
        REP(i, 0, j) {
            ans += arr[i];
        }
        cout << ans << '\n';
    }
}