/* Created by Ishaan Shah on 13-10-2019.
* Problem Name: Pens and Pencils
* Problem Link: https://codeforces.com/contest/1244/problem/A
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
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int x = a/c + (int)(a%c != 0), y = b/d + (int)(b%d != 0);
        if (x + y <= k)
            cout << x << ' ' << y << '\n';
        else
            cout << -1 << '\n';

    }
}