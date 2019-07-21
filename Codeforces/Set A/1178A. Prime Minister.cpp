/* Created by Ishaan Shah on 20-07-2019.
* Problem Name: Prime Minister
* Problem Link: https://codeforces.com/contest/1178/problem/A
*/

#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = (int)a; i < (int)b; i++)

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

    int n, sum = 0;
    cin >> n;
    vi arr(n);
    REP(i, 0, n) {
        cin >> arr[i];
        sum += arr[i];
    }
    int ans = 1, major = arr[0];
    vi coal;
    coal.push_back(1);
    REP(i, 1, n) {
        if (arr[0] >= arr[i]*2) {
            major += arr[i];
            ans++;
            coal.push_back(i+1);
        }
    }
    if (major > sum/2) {
        cout << ans << endl;
        REP (i, 0, ans) {
            cout << coal[i] << ' ';
        }
    } else {
        cout << 0;
    }
}