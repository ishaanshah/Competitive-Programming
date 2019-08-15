/* Created by Ishaan Shah on 10-08-2019.
* Problem Name: Guddu and his Mother
* Problem Link: https://www.codechef.com/AUG19B/problems/KS1
*/

#include <bits/stdc++.h>

#define REP(i, a, b) for(int i = (int)a; i < (int)b; i++)

using namespace std;

typedef long long ll;
typedef vector <ll> vi;
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
        vi arr(n+1), pref_xor(n+1);
        REP(i, 1, n+1) cin >> arr[i];
        pref_xor[1] = arr[1];
        REP(i, 1, n+1)
            pref_xor[i] = pref_xor[i-1]^arr[i];
        ll ans = 0;
        vi size(1000005, 0);
        vi sum(1000005, 0);
        size[0] = 1;
        REP(i, 1, n+1) {
            size[pref_xor[i]]++;
            ans += (i-1)*(size[pref_xor[i]]-1);
            ans -= sum[pref_xor[i]];
            sum[pref_xor[i]] += i;
        }
        cout << ans << endl;
    }
}