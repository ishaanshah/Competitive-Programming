/* Created by Ishaan Shah on 24-11-2019.
* Problem Name: Longest Palindrome
* Problem Link: https://onlinejudge.org/external/111/11151.pdf
*/

#include <bits/stdc++.h>

int memo[1005][1005], vis[1005][1005];

using namespace std;

string s;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int dp(int i, int j) {
    if (i == j)
        return 1;
    if (i > j)
        return 0;
    if (vis[i][j])
        return memo[i][j];
    vis[i][j] = 1;
    if (s[i] == s[j])
        memo[i][j] = dp(i+1, j-1)+2;
    memo[i][j] = max(memo[i][j], dp(i+1, j));
    memo[i][j] = max(memo[i][j], dp(i, j-1));
    return memo[i][j];
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        memset(vis, 0, sizeof(vis));
        memset(memo, 0, sizeof(memo));
        
        getline(cin, s);
        if (s == "") {
            cout << 0 << '\n';
            continue;
        }
        printf("%d\n", dp(0, s.length()-1));
    }
}