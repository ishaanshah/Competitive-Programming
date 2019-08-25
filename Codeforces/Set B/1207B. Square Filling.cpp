/* Created by Ishaan Shah on 22-08-2019.
* Problem Name: Square Filling
* Problem Link: https://codeforces.com/contest/1207/problem/B
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

    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > ans;
    int grd[51][51], vis[51][51], cnt = 0;
    REP(i, 0, n) REP(j, 0, m) {
        cin >> grd[i][j];
        if (grd[i][j]) cnt++;
        vis[i][j] = 0;
    }

    REP(i, 0, n-1) {
        REP(j, 0, m-1) {
            if (grd[i][j] && (grd[i+1][j]) && (grd[i][j+1]) && (grd[i+1][j+1])) {
                vis[i][j] = 1;
                vis[i][j+1] = 1;
                vis[i+1][j] = 1;
                vis[i+1][j+1] = 1;
                ans.emplace_back(make_pair(i+1, j+1));
            }
        }
    }

    REP(i, 0, n) REP(j, 0, m) {
        if (vis[i][j]) cnt--;
    }
    
    if (!cnt) {
        cout << ans.size() << '\n';
        REP(i, 0, ans.size()) {
            cout << ans[i].first << ' ' << ans[i].second << '\n';
        }
    } else {
        cout << -1;
    }
}