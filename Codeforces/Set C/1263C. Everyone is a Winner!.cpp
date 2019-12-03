/* Created by Ishaan Shah on 30-11-2019.
* Problem Name: Everyone is a Winner!
* Problem Link: https://codeforces.com/contest/1263/problem/C
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
        set<int> ans;
        cin >> n;
        ans.insert(0);
        for (int i = 1; i*i <= n; i++) {
            ans.insert(n/i);
            ans.insert(i);
        }
        cout << ans.size() << '\n';
        for (auto it = ans.begin(); it != ans.end(); it = next(it))
            cout << *it << ' ';
        cout << '\n';
    }
}