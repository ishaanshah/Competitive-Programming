/* Created by Ishaan Shah on 24-12-2017.
 * Problem Name: Left-handers, Right-handers and Ambidexters
 * Problem Link: http://codeforces.com/contest/950/problem/A
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);

    int l, r, a;
    int ans;
    cin >> l >> r >> a;
    if(l > r) {
        if(l - r > a) {
            ans = (r + a)*2;
            a = 0;
        }
        else {
            a -= l-r;
            r = l; 
        }

        if(a > 0) {
            ans = ((a/2) + l)*2;
        }
    }
    else if (r > l) {
        if(r - l > a) {
            ans = (l + a)*2;
            a = 0;
        }
        else {
            a -= r-l;
            l = r; 
        }

        if(a > 0) {
            ans = ((a/2) + r)*2;
        }
    }
    if(l == r) {
        ans = ((a/2) + l)*2;
    }
    cout << ans;
}