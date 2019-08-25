/* Created by Ishaan Shah on 22-08-2019.
* Problem Name: There Are Two Types Of Burgers
* Problem Link: https://codeforces.com/contest/1207/problem/A
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
    while(t--) {
        int b, p, f, h, c;
        cin >> b >> p >> f;
        cin >> h >> c;
        int total = b/2, ans = 0;
        if (c > h) {
            ans += min(f, total)*c;
            total -= min(f, total);
            ans += min(p, total)*h;
        } else {
            ans += min(p, total)*h;
            total -= min(p, total);
            ans += min(f, total)*c;
        }
        cout << ans << endl;
    }
}