/* Created by Ishaan Shah on 11-05-2018.
* Problem Name: Change the Signs
* Problem Link: CHSIGNS
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
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long dp[n][3];
        dp[1][0b00] = arr[0] + arr[1];
        dp[1][0b10] = (-arr[0] + arr[1] > 0) ? (-arr[0]+arr[1]) : 1e18;
        dp[1][0b01] = (arr[0] - arr[1] > 0) ? (arr[0]-arr[1]) : 1e18;
        for(int i = 2; i < n; i++) {
            dp[i][0b00] = min(dp[i-1][0b00], dp[i-1][0b10]) + arr[i];

            dp[i][0b01] = min((arr[i-1] - arr[i] > 0) ? dp[i-1][0b00] - arr[i] : 1e18, 
                                (-arr[i-2] + arr[i-1] - arr[i] > 0) ? dp[i-1][0b10] - arr[i] : (1e18));

            dp[i][0b10] = (-arr[i-1] + arr[i] > 0) ? dp[i-1][0b01] + arr[i] : (1e18);
        }

        int temp[n];
        for(int i = 0; i < n; i++) {
            temp[i] = arr[i];
        }

        for(int i = n-1, j = min_element(dp[n-1], dp[n-1]+3) - dp[n-1]; i >= 1; i--) {
            if(j % 2 == 1) temp[i] = -temp[i];
            if(i == 1 && j / 2 == 1) temp[0] = -temp[0];
            if(j == 0 or j == 1) {
                j = (dp[i][j] == dp[i-1][0] + (j == 0 ? arr[i] : -arr[i])) ? 0b00 : 0b10; 
            } else {
                j = 1;
            }
        }

        for(int i = 0; i < n; i++) {
            cout << temp[i] << ' ';
        }
        cout << endl;
    }
}