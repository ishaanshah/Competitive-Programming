/* Created by Ishaan Shah on 14-09-2019.
* Problem Name: Koala and Lights
* Problem Link: https://codeforces.com/contest/1209/problem/B
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

    int n;
    string s;
    cin >> n >> s;
    vii par(n);
    int mb = -1;
    int ans = -1;
    REP(i, 0, n) {
        cin >> par[i].first >> par[i].second; 
        mb = max(mb, par[i].second);
    }

    REP(i, 0, 10000) {
        int tmp = 0;
        REP(j, 0, n) {
            int t = i-par[j].second;
            if (((t/par[j].first)%2 == 0) && t >= 0)
                tmp += (s[j]-'0')^1;
            else
                tmp += (s[j]-'0');
        }
        ans = max(tmp, ans);
    }

    cout << ans;
}