/* Created by Ishaan Shah on 01-10-2019.
* Problem Name: Equalize Prices Again
* Problem Link: https://codeforces.com/contest/1234/problem/A
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

    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vi arr(n);
        REP(i, 0, n) cin >> arr[i];
        ll sum = 0;
        REP(i, 0, n) sum += arr[i];
        int lo = 0, hi = 10000005, mid;
        ll ans = 1e9+10;
        while (lo <= hi) {
            mid = (lo+hi)/2;
            if (mid*n < sum) {
                lo = mid+1;
            } else {
                ans = mid;
                hi = mid-1;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}