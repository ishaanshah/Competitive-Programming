/* Created by Ishaan Shah on 14-09-2019.
* Problem Name: Paint the Digits
* Problem Link: https://codeforces.com/contest/1209/problem/C
*/

#include <bits/stdc++.h>

#define REP(i, a, b) for(int i = (int)a; i < (int)b; i++)

using namespace std;

typedef long long ll;
typedef vector <int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    #endif

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int thr;
        vector<char> ans;
        int minf[n], maxb[n];
        minf[n-1] = s[n-1]-'0';
        for (int i = n-2; i >= 0; i--) {
            minf[i] = min(minf[i+1], s[i]-'0');
        }
        maxb[0] = s[0]-'0';
        for (int i = 1; i < n; i++) {
            maxb[i] = max(maxb[i-1], s[i]-'0');
        }
        for (thr = 0; thr < 10; thr++) {
            ans.clear();
            int m1 = 0, m2 = 0;
            REP(i, 0, n) {
                int num = s[i]-'0';
                if (num == thr) {
                    int val1 = 0, val2 = 0;
                    if (i < n-1)
                        if (minf[i+1] < thr) val1 = 1;
                    if (i > 0)
                        if (maxb[i-1] > thr) val2 = 1;

                    if (val1 & val2) continue;
                    else if (val1 & !val2) {
                        ans.push_back('2');
                        m2 = max(m2, num);
                    } else if (!val1 & val2) {
                        ans.push_back('1');
                        m1 = max(m1, num);
                    } else {
                        ans.push_back('1');
                        m1 = max(m1, num);
                    }              
                }
                else if (num < thr) {
                    if (num >= m1) {
                        ans.push_back('1');
                        m1 = max(m1, num);
                    } else
                        continue;
                } else {
                    if (num >= m2) {
                        ans.push_back('2');
                        m2 = max(m2, num);
                    } else
                        continue;
                }
            }
            if (ans.size() == n) break;
        }
        if (ans.size() == n)
            REP(i, 0, n) cout << ans[i];
        else cout << '-';

        cout << '\n';
    }
}