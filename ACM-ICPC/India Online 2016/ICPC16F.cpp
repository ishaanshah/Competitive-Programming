/* Created by Ishaan Shah on 27-09-2019.
* Problem Name: Chef and Bipartite Graphs
* Problem Link: https://www.codechef.com/ACMIND16/problems/ICPC16F
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
        int n, m, d, D;
        cin >> n >> m >> d >> D;
        if (m == 0) {
            cout << -1 << '\n';
            continue;
        }
        vii ans;
        int bar = 0;
        int mind = 0, maxd = 0;
        int vtx = 0;
        while (m--) {
            if (vtx%n == 0) {
                maxd++;
            }
            ans.push_back(make_pair(vtx%n + 1, (vtx+bar)%n + 1));
            vtx++;
            if (vtx%n == 0) {
                mind++;
                bar++;
            }   
        }
        if (mind >= d && maxd <= D) {
            for (int i = 0; i < ans.size(); i++) {
                cout << ans[i].first << ' ' << ans[i].second << '\n'; 
            }
        } else {
            cout << -1 << '\n';
        }
    }
    return 0;
}