/* Created by Ishaan Shah on 21/1/18
 * Problem Name: SURVIVE
 * Problem Link: https://www.codechef.com/COOK90/problems/SURVIVE
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    double t,k, n, s;
    cin >> t;
    while (t--) {
        cin >> n >> k >> s;
        double total = k*s;
        int days = s-int((s/7));
        if(days*n >= total) {
            cout << ceil(total/n);
        } else {
            cout << "-1";
        }
        cout << endl;
    }
}