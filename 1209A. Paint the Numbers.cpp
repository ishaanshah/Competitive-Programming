/* Created by Ishaan Shah on 14-09-2019.
* Problem Name: Paint the Numbers
* Problem Link: https://codeforces.com/contest/1209/problem/A 
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
    cin >> n;
    set<int> arr;
    REP(i, 0, n) {
        int t;
        cin >> t;
        arr.insert(t);
    }
    int ans = 0;
    while (!arr.empty()) {
        int mx = *prev(arr.end());
        int t = *arr.begin();
        ans++;
        arr.erase(t);
        int cnt = 2;
        while (cnt*t <= mx && !arr.empty()) {
            arr.erase(cnt*t);
            cnt++;
        }
    }
    cout << ans;
}