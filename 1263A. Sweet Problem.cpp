/* Created by Ishaan Shah on 30-11-2019.
* Problem Name: Sweet Problem
* Problem Link: https://codeforces.com/contest/1263/problem/A
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
        int inp[3];
        cin >> inp[0] >> inp[1] >> inp[2];
        sort(inp, inp+3);
        int ans = 0, tmp = min(inp[2]-inp[1], inp[0]);
        ans += tmp;
        inp[2] -= tmp;
        inp[0] -= tmp;
        inp[2] -= inp[0]/2;
        inp[1] -= inp[0]/2;
        ans += 2*(inp[0]/2);
        ans += min(inp[1], inp[2]);
        cout << ans << '\n';
    }
}