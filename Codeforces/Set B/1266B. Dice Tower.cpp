/* Created by Ishaan Shah on 17-12-2019.
* Problem Name: Dice Tower
* Problem Link: http://codeforces.com/contest/1266/problem/B
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
        ll n;
        cin >> n;
        if (n <= 21) {
            if (21-n > 6 || n == 21)
                cout << "NO" << '\n';
            else   
                cout << "YES" << '\n';
            continue;
        }
        n -= 21;
        ll k = n/14 + 1;
        if (k*14 - n > 6)
            cout << "NO" << '\n';
        else
            cout << "YES" << '\n';
    }
    return 0;
}