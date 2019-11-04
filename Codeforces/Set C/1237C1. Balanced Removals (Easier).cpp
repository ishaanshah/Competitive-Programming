/* Created by Ishaan Shah on 16-10-2019.
* Problem Name: Balanced Removals (Easier)S
* Problem Link: https://codeforces.com/contest/1237
*/

#include <bits/stdc++.h>

#define REP(i, a, b) for(int i = (int)a; i < (int)b; i++)

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair <pair <int, int>, pair <int, int> > pnt;

ll dist(pnt a, pnt b) {
    ll res = abs((a.first.first-b.first.first));//*(a.first.first-b.first.first);
    res += abs((a.first.second-b.first.second));//*(a.first.second-b.first.second);
    res += abs((a.second.first-b.second.first));//*(a.second.first-b.second.first);
    return res;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n;
    cin >> n;
    vector<pnt> pnts(n);
    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        pnts[i].first.first = x;
        pnts[i].first.second = y;
        pnts[i].second.first = z;
        pnts[i].second.second = i+1;
    }
    sort(pnts.begin(), pnts.end());

    for (int i = 0; i < n/2; i++) {
        int len = pnts.size(), idx = 0;
        ll mn = 1e18;
        for (int j = 1; j < len; j++) {
            if (mn > dist(pnts[0], pnts[j])) {
                mn = dist(pnts[0], pnts[j]);
                idx = j;
            }
        }
        cout << pnts[idx].second.second << ' ' << pnts[0].second.second << '\n';
        pnts.erase(pnts.begin()+idx);
        pnts.erase(pnts.begin());
        sort(pnts.begin(), pnts.end());
    }
}