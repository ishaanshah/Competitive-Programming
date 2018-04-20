/* Created by Ishaan Shah on 10-04-2018.
 * Problem Name: CHEFWORK
 * Problem Link: https://www.codechef.com/APRIL18B/problems/CHEFWORK
*/


#include <bits/stdc++.h>

using namespace std;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n;
    cin >> n;
    int c[n];
    int at = 10000000;
    int tr = at;
    int a = at;
    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if(t == 1) {
            tr = min(tr, c[i]);
        } else if (t == 2) {
            a = min(a, c[i]);
        } else {
            at = min(at, c[i]);
        }
    }
    cout << min(a+tr, at) << endl;
}