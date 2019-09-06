/* Created by Ishaan Shah on 30-08-2019.
* Problem Name: Equalizing by Division
* Problem Link: https://codeforces.com/contest/1213/problem/D1
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

    int n, k;
    cin >> n >> k;
    vi arr(n);
    REP(i, 0, n) cin >> arr[i];
    int ans = 1e9;
    REP(i, 1, 200005) {
        int curr = 0;
        vi tmp2;
        REP(j, 0, n) {
            if (arr[j] >= i) {
                int tmp = 0, cpy = arr[j];
                if (cpy == i) tmp2.push_back(0);
                while (cpy > i) {
                    cpy /= 2;
                    tmp++;
                    if (cpy == i) 
                        tmp2.push_back(tmp);
                }
            }
        }
        if (tmp2.size() >= k) {
            sort(tmp2.begin(), tmp2.end());
            REP(l, 0, k)
                curr += tmp2[l];
        } else {
            curr = 1e9;
        }
        ans = min(ans, curr);
    }
    cout << ans;
}