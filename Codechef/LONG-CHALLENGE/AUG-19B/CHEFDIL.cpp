/* Created by Ishaan Shah on 10-08-2019.
* Problem Name: Dilemma
* Problem Link: https://www.codechef.com/AUG19B/problems/CHEFDIL
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
        string s;
        cin >> s;
        int n = (int)s.size(), cnt = 0;
        REP(i, 0, n) if (s[i] == '0') cnt++;
        if (n%2 == 1) {
            if (cnt%2 == 0) cout << "WIN";
            else cout << "LOSE";
        } else {
            if (cnt%2 == 1) cout << "WIN";
            else cout << "LOSE";
        }
        cout << endl;
    }
}