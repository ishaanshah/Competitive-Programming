/* Created by Ishaan Shah on 01-10-2019.
* Problem Name: Pipes
* Problem Link: https://codeforces.com/contest/1234/problem/C
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
        int n, flag = 1;
        cin >> n;
        string s[2];
        cin >> s[0] >> s[1];
        pair<int, int> curr, last;
        last.first = 1; last.second = 0;
        curr.first = 1; curr.second = 1;
        while (true) {
            int a = curr.first-1, b = curr.second-1;
            int x = last.first-1, y = last.second-1;
            if (curr.first == 2 && curr.second == n+1)
                break;
            if (curr.second > n && curr.first == 1) {
                flag = 0;
                break;
            }
            if (s[a][b]-'0' > 2) {
                if (a == x) {
                    last.first = a + 1;
                    last.second = curr.second;
                    curr.first = !a + 1;
                } else {
                    last.second = b + 1;
                    last.first = curr.first;
                    curr.second = b + 2;
                }
            } else {
                if (a == x) {
                    last.second = b + 1;
                    last.first = curr.first;
                    curr.second = b + 2;
                } else {
                    flag = 0;
                    break;
                }
            }
        }
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
}
