/* Created by Ishaan Shah on 14-04-2018.
* Problem Name: AVGPR
* Problem Link: https://www.codechef.com/APRIL18B/problems/AVGPR
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
        long long freq[2001];

        for(int i = 0; i < 2001; i++) {
            freq[i] = 0;
        }

        for(int i = 0; i < n; i++) {
            cin >> arr[i];
            arr[i] += 1000;
            freq[arr[i]]++;
        }

        long long ans = 0;
        for(int i = 0; i <= 2000; i++) {
            for(int j = 0; j <= 2000; j++) {
                if(freq[i] > 0 and freq[j] > 0) {
                    if((i + j) % 2 == 0 and freq[(i+j)/2] > 0) {
                        if(i == j) {
                            ans += (freq[i]-1)*(freq[j]);
                        }
                        else {
                            ans += freq[i] * freq[j];
                        }
                    }
                }
            }
        }
        ans /= 2;
        cout << ans << endl;
    }
}