/* Created by Ishaan Shah on 13-10-2019.
* Problem Name: Rooms and Staircases
* Problem Link: https://codeforces.com/contest/1244/problem/B
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
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = 0;
        REP(i, 0, n) {
            if (s[i]-'0' == 1)
                ans++;
            ans++;
        }
        REP(i, 0, n) {
            if (s[i]-'0' == 1) {
                ans = max((i+1)*2, ans);
            }
        }
        for (int i = n-1; i >= 0; i--) {
            if (s[i]-'0' == 1) {
                ans = max((n-i)*2, ans);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}