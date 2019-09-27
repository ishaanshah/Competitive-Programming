/* Created by Ishaan Shah on 23-09-2019.
* Problem Name: Ania and Minimizing
* Problem Link: https://codeforces.com/contest/1230/problem/B
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

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (n == 1 && k > 0) {
        cout << 0;
        return 0;
    }
    if (s[0] != '1' && k > 0) {
        s[0] = '1';
        k--;
    }
    for (int i = 1; i < n && k > 0; i++) {
        if (s[i] != '0') {
            k--;
            s[i] = '0';
        }
    }
    cout << s;

    return 0;
}