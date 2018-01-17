/* Created by Ishaan Shah on 28-12-2017.
 * Problem Name: INOI1602
 * Problem Link: https://www.codechef.com/INOIPRAC/problems/INOI1602
*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > memo;
int b[701];
int v[701];
int n, k;

int dp(int i,int j) {
    if(i >= j) {
        memo[i][j] = 0;
        return 0;
    }
    if(memo[i][j] != -1) {
        return memo[i][j];
    }

    int ans = numeric_limits<int>::min();
    for(int x = i + 1; x < j; x++) {
        if(b[x] == b[i] + k) {
            ans = max(dp(i + 1, x - 1) + dp(x + 1, j) + v[i] + v[x], ans);
        }
        if(b[x] + k == b[j]) {
            ans = max(dp(i, x - 1) + dp(x + 1, j - 1) + v[j] + v[x], ans);
        }
    }
    if(b[i] + k == b[j]) {
        ans = max(dp(i + 1, j - 1) + v[j] + v[i], ans);
    }
    ans = max(ans, max(dp(i + 1, j), dp(i, j - 1)));
    memo[i][j] = ans;

    return ans;
}

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for(int i = 0; i < n; i++) {
        memo.emplace_back(vector<int>(n, -1));
    }
    int ans = dp(0, n-1);
    cout << ans;
}