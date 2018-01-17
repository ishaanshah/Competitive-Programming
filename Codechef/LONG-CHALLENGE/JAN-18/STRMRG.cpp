/* Created by Ishaan Shah on 11-01-2018.
 * Problem Name: STRMRG
 * Problem Link: https://www.codechef.com/JAN18/problems/STRMRG
*/

#include <bits/stdc++.h>

using namespace std;

vector<char> a, b;
vector<vector<int> > dp;


int lcs(int m, int n) {
    if (m < 0 or n < 0) {
        return 0;
    }

    if(dp[m][n] == -1) {
        if (a[m] == b[n]) {
            dp[m][n] = 1 + lcs(m - 1, n - 1);
        } else {
            dp[m][n] = max(lcs(m - 1, n), lcs(m, n - 1));
        }
    }
    return dp[m][n];
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        dp.resize(5005, vector<int>(5005, -1));

        char temp;
        char last = '1';
        for(int i = 0; i < n; i++) {
            cin >> temp;
            if(temp != last) {
                a.push_back(temp);
            }
            last = temp;
        }
        last = '1';
        for(int i = 0; i < m; i++) {
            cin >> temp;
            if(last != temp) {
                b.push_back(temp);
            }
            last = temp;
        }
        cout << a.size()+b.size() - lcs(a.size()-1, b.size()-1) << endl;
        a.clear();
        b.clear();
        dp.clear();
    }
}