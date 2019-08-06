/* Created by Ishaan Shah on 06-08-2019.
* Problem Name: Football
* Problem Link: https://www.codechef.com/AUG19B/problems/MSNSADM1
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
        int n, ans = -1;
        cin >> n;
        vi a(n), b(n), score(n, 0);
        REP(i, 0, n) cin >> a[i];
        REP(i, 0, n) cin >> b[i];
        REP(i, 0, n) {
            score[i] += a[i]*20;
            score[i] -= b[i]*10;
            score[i] = max(score[i], 0);
            ans = max(ans, score[i]);
        }
        cout << ans << endl;
    }
}