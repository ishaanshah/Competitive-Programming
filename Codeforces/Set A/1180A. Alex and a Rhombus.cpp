/* Created by Ishaan Shah on 21-06-2019
 * Problem Name: Alex and a Rhombus
 * Problem Link: https://codeforces.com/contest/1180/problem/A
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.in", "w", stdout);
    #endif

    int n;
    cin >> n;
    cout << n*n + (n-1)*(n-1);
}