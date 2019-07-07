/* Created by Ishaan Shah on 05-07-2019.
* Problem Name: Chef and Mean
* Problem Link: https://www.codechef.com/JULY19B/problems/CHFM/
*/

#include <bits/stdc++.h>

#define eps 1e-9

using namespace std;

typedef long long ll;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif
    
    ll t, n, arr[100005], sum;
    cin >> t;
    while(t--) {
        cin >> n;
        sum = 0;
        double avg;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
        }
        avg = (double)sum/(double)n;
        ll idx = n+1;
        for (ll i = 0; i < n; i++) 
            if (abs(avg-((double)(sum-arr[i])/(double)(n-1))) < eps)
                idx = min(idx, i+1);
        if (idx == n+1) {
            cout << "Impossible";
        } else {
            cout << idx;
        }
        cout << endl;
    }
}