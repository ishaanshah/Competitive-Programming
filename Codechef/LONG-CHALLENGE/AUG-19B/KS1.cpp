/* Created by Ishaan Shah on 10-08-2019.
* Problem Name: Guddu and his Mother
* Problem Link: https://www.codechef.com/AUG19B/problems/KS1
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
        vi arr(n), pref_xor(n);
        REP(i, 0, n) cin >> arr[i];
        pref_xor[0] = arr[0];
        REP(i, 1, n)
            pref_xor[i] = pref_xor[i-1]^arr[i];
        int ans = 0;
        REP(i, 0, n) {
            REP(j, i+1, n) {
                if (i == 0) {
                    if (arr[j] == pref_xor[j-1]) ans += j;
                }
                else {
                    if (arr[j] == (pref_xor[j-1]^pref_xor[i-1])) 
                        ans += j-i;
                }
            }
        }
        cout << ans << endl;
    }
}