/* Created by Ishaan Shah on 05-01-2018.
 * Problem Name: MAXSC
 * Problem Link: https://www.codechef.com/JAN18/problems/MAXSC
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        long long grid[n][n];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
            sort(grid[i], grid[i]+n);
        }
        long long sum = grid[n-1][n-1];
        long long max = grid[n-1][n-1];
        for(int i = n-2; i >= 0; i--) {
            long long *ptr = lower_bound(grid[i], grid[i] + n, max);
            if(ptr > grid[i]) {
                max = *(ptr-1);
                sum += *(ptr-1);
            } else {
                sum = -1;
                break;
            }
        }
        cout << sum << endl;
    }
}
