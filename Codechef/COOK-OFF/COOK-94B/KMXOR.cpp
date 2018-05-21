/* Created by Ishaan Shah on 21-05-2018.
* Problem Name: Best Cake Ever
* Problem Link: https://www.codechef.com/COOK94B/problems/KMXOR
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t;
    cin >> t;   
    while(t--) {
        unsigned long long n, k;
        cin >> n >> k;
        if(n == 1) {
            cout << k << endl;
            continue;
        }
        if(k == 1) {
            for(int i = 0; i < n; i++) {
                cout << 1 << ' ';
            }
            cout << endl;
            continue;
        }
        if(n % 2 == 0) {
            int temp = 0;
            while(k) {
                k = k/2;
                temp++;
            }
            int ans = pow(2, temp-1);
            cout << ans << ' ' << ans-1 << ' ';
            for(int i = 0; i < n-2; i++) {
                cout << 1 << ' ';
            }
            cout << endl;
        } else {
            int temp = 0;
            for(int i = 0; i < n-3; i++) {
                cout << 1 << ' ';
            }
            if(k == 3) {
                cout << 1 << ' ' << 1 << ' ' << 3 << endl;
                continue;
            }
            if(k == 2) {
                cout << 1 << ' ' << 1 << ' ' << 2 << endl;
                continue;
            }
            while(k) {
                temp++;
                k = k/2;
            }
            int ans = pow(2, temp-1);
            cout << ans << ' ' << ans/2 << ' ' << ans/2-1 << endl;
        }
        cout << endl;
    }
}