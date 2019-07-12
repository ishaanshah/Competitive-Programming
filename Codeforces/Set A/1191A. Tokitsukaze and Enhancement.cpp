/* Created by Ishaan Shah on 12-07-2019.
* Problem Name: Tokitsukaze and Enhancement
* Problem Link: https://codeforces.com/contest/1191/problem/A
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int n;
    cin >> n;
    if (n%4 == 0) cout << 1 << " A";   
    else if (n%4 == 1) cout << 0 << " A";
    else if (n%4 == 2) cout << 1 << " B";
    else cout << 2 << " A";
}
