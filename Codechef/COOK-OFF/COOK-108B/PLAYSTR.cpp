/* Created by Ishaan Shah on 21-07-2019.
* Problem Name: Playing with Strings
* Problem Link: https://www.codechef.com/COOK108B/problems/PLAYSTR
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
    while(t--) {
        int n;
        string r, s;
        cin >> n;
        cin >> s >> r;
        int cnt1s = 0, cnt0s = 0, cnt1r = 0, cnt0r = 0;
        REP(i, 0, n) {
            if (s[i] == '1') cnt1s++;
            else cnt0s++;
            if (r[i] == '1') cnt1r++;
            else cnt0r++;
        }
        if (cnt0s == cnt0r) cout << "YES";
        else cout << "NO";
        cout << '\n';
    }
}