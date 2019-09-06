/* Created by Ishaan Shah on 30-08-2019.
* Problem Name: Chips Moving
* Problem Link: https://codeforces.com/contest/1213/problem/A
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
    vi arr(n);
    int ans = 1e9;
    REP(i, 0, n) cin >> arr[i];
    REP(i, 0, n) {
        int curr = 0;
        REP(j, 0, n) {
            if ((arr[i]%2)^(arr[j]%2)) 
                curr++;
        }
        ans = min(ans, curr);
    }
    cout << ans;
}