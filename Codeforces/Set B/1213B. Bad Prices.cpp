/* Created by Ishaan Shah on 30-08-2019.
* Problem Name: Bad Prices
* Problem Link: https://codeforces.com/contest/1213/problem/B
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
        cin >> n;
        vii arr(n);
        REP(i, 0, n) {
            cin >> arr[i].first;
            arr[i].second = i+1;
        }
        sort(arr.begin(), arr.end());
        int ans = 0, lst = 0, i = 0;
        while (true) {
            if (arr[i].second > lst) {
                ans += arr[i].second-lst-1;
                lst = arr[i].second;
            }
            if (arr[i].second == n || i == n-1) break;
            i++;
        }
        cout << ans << '\n';
    }
}