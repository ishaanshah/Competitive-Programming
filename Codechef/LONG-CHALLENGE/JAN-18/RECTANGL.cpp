/* Created by Ishaan Shah on 05-01-2018.
 * Problem Name: RECTANGL
 * Problem Link: https://www.codechef.com/JAN18/problems/RECTANGL
*/

#include<bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c, d, t;
    cin >> t;
    while(t--) {
        cin >> a >> b >> c >> d;
        if (a == b and c == d) {
            cout << "YES";
        } else if (a == c and b == d) {
            cout << "YES";
        } else if (a == d and b == c) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << endl;
    }
}