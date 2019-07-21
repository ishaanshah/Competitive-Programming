/* Created by Ishaan Shah on 20-07-2019.
* Problem Name: WOW Factor
* Problem Link: https://codeforces.com/contest/1178/problem/B
*/

#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = (int)a; i < (int)b; i++)

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

    string s;
    cin >> s;
    ll len = s.size();
    ll left = 0, right = 0, ans = 0, streak = 0;
    REP(i, 0, len) {
        if (s[i] == 'v') streak++;
        else {
            right += max(streak-1, 0ll);
            streak = 0;
        }
    }
    right += max(streak-1, 0ll);
    streak = 0;
    REP(i, 0, len) {
        if (s[i] == 'v') {
            streak++;
        } else {
            right -= max(streak-1, 0ll);
            left += max(streak-1, 0ll);
            ans += left*right;
            streak = 0;
        }
    }
    cout << ans;
}