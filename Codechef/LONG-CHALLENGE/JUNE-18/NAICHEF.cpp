/* Created by Ishaan Shah on 01-06-2018.
* Problem Name: Naive Chef
* Problem Link: https://www.codechef.com/JUNE18B/problems/NAICHEF
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
        double n, a, b;
        cin >> n >> a >> b;
        vector<double> count(n, 0);
        
        for(double i = 0; i < n; i++) {
            double x;
            cin >> x;
            count[x-1] += 1;
        }
        cout << (count[a-1]/n) * (count[b-1]/n) << endl;
    }
}