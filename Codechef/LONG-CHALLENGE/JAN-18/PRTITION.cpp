/* Created by Ishaan Shah on 09-01-2018.
 * Problem Name: PRTITION
 * Problem Link: https://www.codechef.com/JAN18/problems/PRTITION
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n, x;
    while(t--) {
        cin >> x >> n;
        int total = n*(n+1)/2;
        total -= x;
        if(total%2 == 0) {

        } else {
            cout << "impossible" << endl;
        }
    }
}