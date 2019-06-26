/* Created by Ishaan Shah on 26-06-2019.
* Problem Name: Equalize Prices
* Problem Link: https://codeforces.com/contest/1183/problem/B
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int mx, mn, tmp;
        mn = 1e10; mx = 0;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            mx = max(mx, tmp);
            mn = min(mn, tmp);
        }
        if (mx-k <= mn+k) cout << mn+k << endl;
        else cout << -1 << endl;
    }
}