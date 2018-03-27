/* Created by Ishaan Shah on 18-03-2018.
 * Problem Name: CO92SUBW
 * Problem Link: https://www.codechef.com/COOK92B/problems/CO92SUBW
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);

    int t;
    cin >> t;
    while(t--) {
        long long x;
        cin >> x;
        double root = (-1 + sqrt(1+(8*x)))/2;
        long long d1 = ceil(root)*(ceil(root) + 1)*(0.5);
        long long d2 = floor(root)*(floor(root) + 1)*(0.5);
        cout << min(ceil(root) + d1 - x, floor(root) + x - d2) << endl;
    }
}