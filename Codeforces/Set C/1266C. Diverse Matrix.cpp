/* Created by Ishaan Shah on 17-12-2019.
* Problem Name: Diverse Matrix
* Problem Link: http://codeforces.com/contest/1266/problem/C
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

    int r, c;
    cin >> r >> c;
    if (r == 1 && c == 1) {
        cout << 0;
        return 0;
    }
    if (c == 1) {
        for (int i = 0; i < r; i++)
            cout << i+2 << '\n';
        return 0;
    }
    int ans[505][505];
    for (int i = 0; i < c; i++)
        ans[0][i] = i+2;
    
    for (int i = 1; i < r; i++) {
        for (int j = 0; j < c; j++) {
            ans[i][j] = (c+i+1)*ans[0][j];
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}