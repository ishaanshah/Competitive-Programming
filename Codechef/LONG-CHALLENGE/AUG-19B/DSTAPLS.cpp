/* Created by Ishaan Shah on 06-08-2019.
* Problem Name: Distribute Apples
* Problem Link: https://www.codechef.com/AUG19B/problems/DSTAPLS
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

    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        if ((n/k)%k == 0) cout << "NO";
        else cout << "YES";
        cout << endl;
    }
}