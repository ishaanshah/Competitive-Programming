/* Created by Ishaan Shah on 09-06-2019.
* Problem Name: Guddu on a Date
* Problem Link: https://www.codechef.com/JUNE19B/problems/KS2
*/

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    ull t;
    cin >> t;
    while (t--) {
        ull n, sum = 0;
        cin >> n;
        ull n_c = n;
        while (n) {
            sum += n%10;
            n = n/10;
        }
        cout << n_c;
        if (sum%10 != 0) {
            ull mult = 10*ceil(sum/10.0);
            cout << mult-sum;
            cout << endl;
        } else {
            cout << '0' << endl;
        }
        
    }
}