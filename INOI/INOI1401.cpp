/* Created by Ishaan Shah on 18-12-2017.
 * Problem Name: INOI1401
 * Problem Link: https://www.codechef.com/INOIPRAC/problems/INOI1401
*/
#include <bits/stdc++.h>

using namespace std;

int r, c, d;

int main() {
    cin >> r >> c >> d;
    int grid[r][c];
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            int a;
            cin >> grid[i][j];
            if(!grid[i][j]) {
            }
        }
    }
    int ans[r][c];
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            ans[i][j] = 0;
        }
    }
    ans[0][0] = grid[0][0];
    bool zero = false;
    for(int i = 1; i < r; i++) {
        if(!grid[i][0] or i > d) {
            zero = true;
        }
        if(zero) {
            ans[i][0] = 0;
        }
        else {
            ans[i][0] = 1;
        }
    }
    zero = false;
    for(int i = 1; i < c; i++) {
        if(!grid[0][i] or i > d) {
            zero = true;
        }
        if(zero) {
            ans[0][i] = 0;
        }
        else {
            ans[0][i] = 1;
        }
    }
    for(int i = 1; i < r; i++) {
        for(int j = 1;  j < c; j++) {
            if (grid[i][j]) {
                ans[i][j] += ans[i - 1][j] + ans[i][j - 1];
                int k = j - 1;
                while (grid[i][k] and k >= 0 and j-k <= d+1) {
                    if (j - k > d) {
                        ans[i][j] -= ans[i - 1][k];
                    }
                    k--;
                }
                k = i - 1;
                while (grid[k][j] and k >= 0 and i-k <= d+1) {
                    if (i - k > d) {
                        ans[i][j] -= ans[k][j - 1];
                    }
                    k--;
                }
                ans[i][j] = (ans[i][j] + 20011) % 20011;
            }
        }
    }
    cout << ans[r-1][c-1];
}
